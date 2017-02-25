#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int A=1000000+100000+10;
int n,ans=2100000000;
int a[A]={0};
/*
int judge(int x)
{
	
	
}
*/
int sum(int x,int y)
{
	int i,ss=0;
	for(i=x;i<=y;i++)
		ss+=a[i];
	return ss;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("rectangle.in","r",stdin);
	fout=freopen("rectangle.out","w",stdout);
	
	cin>>n;
	int i,j;
	int tl,tr,tw,th;
	for(i=1;i<=n;i++)
	{
		cin>>tl>>tr>>tw>>th;
		for(j=tl;j<=tl+tw;j++)
			a[j]+=th;
	}
//	for(i=1;i<=100;i++)
//		cout<<a[i]<<" ";
	int l=0,r=A,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
	//	cout<<"\n"<<"l="<<l<<" r="<<r<<" mid="<<mid;
		int ttl=sum(0,mid),ttr=sum(mid,A-1);
		if(ttl<ttr) l=mid;
		if(ttl>ttr) r=mid;
		if(ttl==ttr)
		{
	//		cout<<"\n"<<mid<<"\n";
			while(a[mid]==0)
				mid--;
	//		cout<<mid<<"\n";
			fclose(fin);fclose(fout);
			return 0;
		}
		if(ans>abs(ttl-ttr)) ans=abs(ttl-ttr);
	}
	
//	cout<<"\n"<<ans<<"\n";
	
	if(abs(sum(0,l)-sum(l,A-1))==ans) cout<<l<<"\n";
	else if(abs(sum(0,mid)-sum(mid,A-1))==ans) cout<<mid<<"\n";
	else if(abs(sum(0,r)-sum(r,A-1))==ans) cout<<r<<"\n";
	fclose(fin);fclose(fout);
	return 0;
}
