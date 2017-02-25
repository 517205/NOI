#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define M 1000010
int a[M],d[M],x[M],y[M],s[M],sum,ans=0,n,m;
//a=number of classroom,x=start,y=end,d=day
int judge(int v)//v=mid
{
	int i;
	memset(s,0,sizeof(s));
	sum=0;
	for(i=1;i<=v;i++)
	{
		s[x[i]]+=d[i];
		s[y[i]+1]-=d[i];
	}
	for(i=1;i<=n;i++)
	{
		sum+=s[i];
		if(sum>a[i]) return 0;
	}
	return 1;
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("classroom.in","r",stdin);
	fout=freopen("classroom.out","w",stdout);
	
	int i;
	scanf("%d%d",&n,&m);//n=day,m=number of list
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&d[i],&x[i],&y[i]);
	int left=1,right=m;
	int mid=(left+right)/2;
	while(left<right)
	{
		if(!judge(mid))
		{
			ans=mid;
			right=mid-1;
		}
		else left=mid-1;
	}
	if(ans==0)
		printf("0\n");
	else
		printf("-1\n%d\n",ans);
	fclose(fin);fclose(fout);
	return 0;
}
