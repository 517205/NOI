#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int mm=10000+10;
int a[mm][mm],sum[mm][mm];
int m,n;
int tmp,ans=1<<31;
int main()
{
	FILE *fin,*fout;
	fin=freopen("maxson.in","r",stdin);
	fout=freopen("maxson.out","w",stdout);
	
	int i,j,k;//O(n*m*m)
	cin>>n;m=n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
//	for(i=1;i<=m;i++)
//	{
//		for(j=1;j<=n;j++)
//			cout<<sum[i][j]<<' ';
//		cout<<endl;
//	}
	for(i=1;i<=m;i++)
	{
		for(j=i;j<=m;j++)
		{
			
			for(k=1;k<=n;k++)
			{
				tmp+=sum[k][j]-sum[k][i-1];
//				printf("<i=%d,j=%d,k=%d>ans=%d,tmp=%d\n",i,j,k,ans,tmp);
				if(tmp>ans)
					ans=tmp;
				else// tmp=0;
				{
					if(tmp<0) tmp=0;
				}
			}
			tmp=0;
		}
	}
	
	
	
	cout<<ans<<endl;
//	cout<<(sum[2][4]-sum[2][2-1])<<endl;
	fclose(fin);fclose(fout);
	return 0;
}
