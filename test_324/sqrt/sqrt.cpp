#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char stmp[201];
struct huge
{
	int len;
	int num[201];
};
huge set(huge x)
{
	x.len=0;
	memset(x.num,0,sizeof(x.num));
	return x;
}
huge s,l,r,mid,mid2,target;
huge middle(huge x,huge y)
{
	int i,maxn;
	huge m;
	m=set(m);
	maxn=max(x.len,y.len);
	for(i=maxn;i>=1;i--)
	{
		if((x.num[i]+y.num[i]+m.num[i])%2==1) m.num[i-1]+=10;
		m.num[i]=(x.num[i]+y.num[i]+m.num[i])/2;
	}
	for(i=1;i<x.len*2+2;i++)
	{
		m.num[i+1]+=m.num[i]/10;
		m.num[i]%=10;
	}
	for(i=200;i>=0;i--)
		if(m.num[i]!=0)
		{
			m.len=i;
			break;
		}
	/*
	if(m.num[maxn]!=0) m.len=maxn;
	else m.len=maxn-1;
	*/
	return m;
}
int cmp(huge x,huge y)//x<=y
{
	if(x.len<y.len) return 1;
	if(x.len>y.len) return 0;
	if(x.len==y.len)
	{
		for(int i=x.len;i>=1;i--)
		{
			if(x.num[i]>y.num[i]) return 0;
			if(x.num[i]<y.num[i]) return 1;
		}
	}
	return 1;
}
huge square(huge x)
{
	huge mul=set(mul);
	int move=0,i,j;
	for(i=1;i<=x.len;i++)
	{
		for(j=1;j<=x.len;j++)
		{
			mul.num[j+move]+=x.num[i]*x.num[j];
		}
		move++;
		for(j=1;j<x.len*2+2;j++)
		{
			mul.num[j+1]+=mul.num[j]/10;
			mul.num[j]%=10;
		}
	}
	for(i=200;i>=0;i--)
		if(mul.num[i]!=0)
		{
			mul.len=i;
			break;
		}
	return mul;
}
huge copy(huge x,huge y)//x<-y
{
	x.len=y.len;
	int i;
	for(i=1;i<=x.len;i++)
		x.num[i]=y.num[i];
	return x;
}
/*
void print(huge x)
{
	int i;
	cout<<x.len<<":";
	for(i=x.len;i>=1;i--)
		printf("%d",x.num[i]);
	if(x.len==0) cout<<0;
	cout<<endl;
}
*/
int equal(huge x,huge y)
{
	if(x.len!=y.len) return 0;
	int i;
	for(i=1;i<=x.len;i++)
		if(x.num[i]!=y.num[i]) return 0;
	return 1;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("sqrt.in","r",stdin);
	fout=freopen("sqrt.out","w",stdout);
	
	int i,point=0;
	s=set(s);l=set(l);r=set(r);mid=set(mid);
	scanf("%s",stmp);
	s.len=strlen(stmp);
	for(i=s.len-1;i>=0;i--)
	{
		point++;
		s.num[point]=stmp[i]-48;
	}
	l.len=0;r=copy(r,s);target=copy(target,s);
	do
	{
		mid2=copy(mid2,mid);
		mid=middle(l,r);
		/*
		cout<<endl;
		cout<<"l   =";
		print(l);
		cout<<"mid =";
		print(mid);
		cout<<"mid^=";
		print(square(mid));
		cout<<"r   =";
		print(r);
		cout<<"mid2=";
		print(mid2);
		cout<<"tar=";
		print(target);
		*/
		if(equal(mid,mid2)==1) break;
		if(cmp(square(mid),target))
		{
			l=copy(l,mid);
		}
		else
		{
			r=copy(r,mid);
		}
	}while(1/*equal(mid,mid2)==0*/);
//	cout<<endl;
//	print(mid);
	
	
	for(i=mid.len;i>=1;i--)
		cout<<mid.num[i];
	if(mid.len==0) cout<<0;
	cout<<endl;
	
	
	
	
		
	
	fclose(fin);fclose(fout);
	return 0;
}
/*
l   =0:0
mid =2:78
mid^=4:6084
r   =3:156
mid2=3:156
tar=5:10000

l   =2:78
mid =3:117
mid^=5:13689
r   =3:156
mid2=2:78
tar=5:10000

l   =3:117
mid =3:136
mid^=5:18496
r   =3:156
mid2=3:117
tar=5:10000
*/
