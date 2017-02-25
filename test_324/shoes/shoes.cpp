#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100000+10;
int dp[N][20];
int n,m,t,k;
int pol2(int x)
{
	int ans=1;
	for(int i=1;i<=x;i++)
		ans*=2;
	return ans;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("shoes.in","r",stdin);
	fout=freopen("shoes.out","w",stdout);
	
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>dp[i][1];
		dp[i][0]=i;
	}
	int kk=log((double)N)/log(2.0);
	for(i=2;i<=kk;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[j][i]=dp[dp[j][i-1]][i-1];
		}
	}
	
	/*
	cout<<n<<" "<<kk<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=kk;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	for(i=1;i<=m;i++)
	{
		cin>>t>>k;
	//	cout<<'<'<<i<<'>'<<endl;
		int ans=0;
		int kk=log((double)k)/log(2.0);
		int tmp=pol2(kk);
		ans=dp[t][kk+1];
	//	printf("t=%d,k=%d,kk=%d,tmp=%d,ans=%d\n",t,k,kk,tmp,ans);
		for(j=1;j<=k-tmp;j++)
		{
			ans=dp[ans][1];
		}
	//	cout<<"ans=";
		cout<<ans<<endl;
		
	}
	
	
	
	fclose(fin);fclose(fout); 
	return 0;
}
