#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

int  b[1000001]={0},path[1000001]={0};//book;
int ans,bsum=0;
int n,m;//n=number of book;m==number of copy;

int judge(int avr)//即mid 
{
	int i,sum,nnn;
	sum=0;nnn=1;
	for(i=n;i>=1;i--)
	{
		if(b[i]>avr) return 0;
		else if(sum+b[i]>avr)
		{
			sum=b[i];//开始另一堆
			nnn+=1;//分堆，堆数加一 
		}
		else sum+=b[i];
	}
	if(nnn>m) return 0;//堆数大于number of copy,fail
	else
	{
		sum=0;
		path[0]=0;
		for(i=n;i>=1;i--)
			if(sum+b[i]>avr)
			{
				sum=b[i];
				path[0]+=1;
				path[path[0]]=i;
			}
			else sum+=b[i];
	}
	return 1;
}

void bin()
{
	int head,tail,mid;
	head=0;tail=bsum;
	while(head<=tail)
	{
		mid=(head+tail)/2;
		if(judge(mid)==0)//failed
			head=mid+1;
		else//succeed
		{
			ans=mid;
			tail=mid-1;
		}
	}
}

int main()
{
    FILE *fin,*fout;
    fin=freopen("copybook.in","r",stdin);
    fout=freopen("copybook.out","w",stdout);
    
    int i,k=1,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
		scanf("%d",&b[i]);
		bsum+=b[i];
	}
	bin();
/*	for(i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n%d\n",bsum);
	
	for(i=0;i<=m;i++)
		printf("%d ",path[i]);
	printf("\n");
*/	int kk=path[0];
	for(i=1;i<=m-1;i++)
	{
		
		printf("%d %d\n",k,path[kk]);
		k=path[kk]+1;
		kk--;
//		printf("%d %d\n",k,k+path[i]);
//		k=k+path[i];
	}
	printf("%d %d\n",k,n);
//	printf("\nTime used:%0.2f",(double)clock()/CLOCKS_PER_SEC);
    fclose(fin);fclose(fout);
    return 0;
}
