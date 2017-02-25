#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

int n,m,sum=0,ans=0;//n=day m=times
int gain[100001]={0};//gain money
int path[100001]={0};


int judge(int mid)
{
	int i,tsum,times;//temporarily sum
	tsum=0;times=1;
	for(i=n;i>=1;i--)
	{
		if(gain[i]>mid)
			return 0;
		else if(tsum+gain[i]>mid)
		{
			times++;
			tsum=gain[i];
		}
		else
			tsum+=gain[i];
	}
	if(times>m) return 0;
	else
	{
		tsum=0;
		path[0]=0;
		for(i=n;i>=1;i--)
		{
			if(tsum+gain[i]>mid)
			{
				tsum=gain[i];
				path[0]+=1;
				path[path[0]]=i;
			}
			else
				tsum+=gain[i];
		}
	}
	return 1;
}

void bin()
{
	int head,tail,mid;
	head=1;tail=sum;
	while(head<tail)
	{
		mid=(head+tail)/2;
		if(judge(mid))//succeed
		{
			ans=mid;
//			tail=mid-1;
			tail=mid;

		}
		else//fail
		{
//			head=mid+1;
			head=mid+1;
		}
	}
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("incomeplan.in","r",stdin);
	fout=freopen("incomeplan.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&gain[i]);
		sum+=gain[i];
	}
	printf("%d\n\n",sum);
	bin();
	printf("%d\n",ans);
//	printf("\nTime used:%0.2f",(double)clock()/CLOCKS_PER_SEC);
	fclose(fin);fclose(fout);
	return 0;
}
