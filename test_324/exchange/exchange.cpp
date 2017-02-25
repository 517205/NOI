#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
struct huge
{
	int a[100];
	int len;
};
char tttt;
int p,q;
char s[100];
huge pp;
huge qq;
huge dd;//dec
int find(huge x)
{
	int i;
	for(i=99;i>=1;i--)
		if(x.a[i]!=0) return i;//作为“len” 
	return 0;
}
huge cls(huge x,int aa)//aa 进制 
{
	huge ans=x;
	int i;
//	memset(ans.a,0,sizeof(ans.a));
	for(i=1;i<=98;i++)
	{
		if(ans.a[i]>=aa)
		{
			ans.a[i+1]+=ans.a[i]/aa;
			ans.a[i]%=aa;
		}
	}
	ans.len=find(ans);
	return ans;
}
huge mul(huge x,int y,int aa)
{
	int i;
	huge ans=x;
	for(i=1;i<=ans.len;i++)
	{
		ans.a[i]*=y;
	}
	ans=cls(ans,aa);
	return ans;
}
huge sum(huge x,huge y,int aa)
{
	int i;
	huge ans;
	memset(ans.a,0,sizeof(ans.a));
	for(i=1;i<=max(x.len,y.len);i++)
	{
		ans.a[i]=x.a[i]+y.a[i];
	}
	ans=cls(ans,aa);
	return ans;
}
void p_exchange_to_dec()
{
	int i,j;
	huge tmp;
	memset(tmp.a,0,sizeof(tmp.a));
	tmp.len=1;
	tmp.a[1]=1;
	for(i=1;i<=pp.len;i++)
	{
		dd=sum(dd,mul(tmp,pp.a[i],10),10);//bug
		tmp=mul(tmp,p,10);//体现“10进制” 
	}
	dd.len=find(dd);
}
int mod(huge x,int y)//y进制 
{
	huge tmp=x;
	int i;
	for(i=tmp.len;i>=2;i--)
	{
		if(tmp.a[i]>y) tmp.a[i]-=(tmp.a[i]/y)*y;
		tmp.a[i-1]+=tmp.a[i]*10;
		tmp.a[i]=0;
	}
	return (tmp.a[1]+tmp.a[2]*10)%y;
}
huge div(huge x,int y)//x/y-----?:x==y
{
	huge tmp=x;
	huge ans;
	ans.len=0;
	memset(ans.a,0,sizeof(ans.a));
	int i;
	for(i=tmp.len;i>=1;i--)
	{
		if(tmp.a[i]>=y)
		{
			ans.a[i]=tmp.a[i]/y;
			tmp.a[i]%=y;
		}
		tmp.a[i-1]+=tmp.a[i]*10;
		tmp.a[i]=0;
	}
	ans=cls(ans,10);
	return ans;
}
void dec_exchange_to_q()//dd->qq,dec->q
{
	int i;
	int point=0;
	huge ddtmp=dd;
	while(ddtmp.len>=3 || (ddtmp.a[1]+ddtmp.a[2]*10)>=q)
	{
		point++;
		qq.a[point]=mod(ddtmp,q);
		ddtmp=div(ddtmp,q);
	}
	qq.a[++point]=(ddtmp.a[1]+ddtmp.a[2]*10)%q;
	qq.len=find(qq);
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("exchange.in","r",stdin);
	fout=freopen("exchange.out","w",stdout);
    
    int n,i,j;
	long long dec;
    char t=' ';
    cin>>n;
	for(i=1;i<=n;i++)
	{
		memset(pp.a,0,sizeof(pp.a));
		memset(qq.a,0,sizeof(qq.a));
		memset(dd.a,0,sizeof(dd.a));
		pp.len=0;qq.len=0;dd.len=0;tttt='a';
		scanf("%d",&p);
		while(tttt!=',') scanf("%c",&tttt);
		j=-1;
		do
		{
			j++;
			cin>>s[j];
			if(s[j]==' ')
				j--;
		}while(s[j]!=',');
		scanf("%d",&q);
		pp.len=j;
		for(j=0;j<pp.len;j++)
		{
			if(s[j]<=48+10) pp.a[pp.len-j]=s[j]-48;
			else pp.a[pp.len-j]=s[j]-55;
		}//OK
		/*
		for(j=pp.len;j>=1;j--)
		{
			if(pp.a[j]<=9) cout<<pp.a[j];
			else printf("%c",pp.a[j]+55);
		}
		cout<<endl;
		*/
		/*
		for(j=1;j<=pp.len;j++)
			cout<<pp.a[j]<<" ";
		cout<<endl;
		*/
		p_exchange_to_dec();
		dec_exchange_to_q();
		/*
		for(j=1;j<=dd.len;j++)
		{
			cout<<dd.a[j]<<" ";
		}
		cout<<endl;
		cout<<dd.len<<endl;
		*/
		int cc=0;
		for(j=qq.len;j>=1;j--)
		{
			cc=1;
			if(qq.a[j]<=9) cout<<qq.a[j];
			else printf("%c",qq.a[j]+55);
		}
		if(cc==0) cout<<0;
		cout<<endl;
	}
//	cout<<endl;
	
	/*
	
	for(i=1;i<=x.len;i++)
		cout<<x.a[i]<<" ";
	cout<<endl;
	x=mul(x,2);
//	x=cls(x,10);

	*/
	/*
	huge x;
	memset(x.a,0,sizeof(x.a));
	x.a[1]=0;
	x.len=0;
	x=cls(x,10);
	huge aaa;
	int aa=mod(x,1);
	cout<<aa;
	*/
	/*
	for(i=1;i<=aaa.len;i++)
		cout<<aaa.a[i]<<" ";
	cout<<endl<<aaa.len<<endl;
	*/
	
    fclose(fin);fclose(fout);
    return 0;
}
