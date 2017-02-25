#include<iostream>
#include<cstdio>
//#include<cmath>
using namespace std;

int n,m,W;//n-number of stone,m-number of interval 
long long int S;
int w[200001],v[200001],l[1000001],r[1000001];//weight,value,left/right interval
int w1[200001],v1[200001];
long long int ans=2100000000;

int calc(int W)
{
	long long int Y=0;//test number
	long long int num0=0,sum0=0;
	long long int i;
	for(i=1;i<=n;i++)
	{
		if(w[i]>W)
		{
			w1[i]=w1[i-1]+1;
			v1[i]=v1[i-1]+v[i];
		}
		else
		{
			w1[i]=w1[i-1];
			v1[i]=v1[i-1];
		}
	}
	for(i=1;i<=m;i++)
		Y+=(w1[r[i]]-w1[l[i]])*(v1[r[i]]-v1[l[i]]);
	return Y-S;
}

int Abs(long long int aaa)
{
	if(aaa>0) return aaa;
	else return -aaa;
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("qc.in","r",stdin);
	fout=freopen("qc.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%lld",&S);
//	printf("%d   %d   %lld   ",n,m,S);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&v[i]);
//		printf("%d %d ",w[i],v[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
//		printf("%d %d ",l[i],r[i]);
	}
	long long int left=1,right=n;
	long long int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		long long int aa=calc(mid);
		if(Abs(aa)<ans)
		{
			ans=Abs(aa);
			if(aa<0) right=mid-1;
			if(aa>0) left=mid+1;
			if(aa==0) break;
		}
		else
		{
			if(aa<0) right=mid-1;
			if(aa>0) left=mid+1;
		}
	}
	printf("%lld\n",ans);
	fclose(fin);fclose(fout);
	return 0;
}
