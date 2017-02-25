#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define maxn 100
int map[maxn][maxn]={0};
int vist[maxn]={0},dist[maxn];
int que[maxn];
int n,e,s,x,y,z,i,head,tail;
void spfa(int u)
{
	int x,i;
	head=0,tail=1;
	que[1]=u;
	dist[u]=0;
	vist[u]=1;
	
	while(head<tail)
	{
		head++;
		x=que[head];
		for(i=1;i<=n;i++)
			if(map[i][x]!=0 && dist[i]>map[i][x]+dist[x])
			{
				dist[i]=map[i][x]+dist[x];
				if(vist[i]==0)
				{
					tail++;
					que[tail]=i;
					vist[i]=1;
				}
			}
		vist[x]=0;
	}
}

int main()
{
	scanf("%d%d",&n,&e);
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z;
		map[y][x]=z;
	}
	memset(dist,127,sizeof(dist));
	scanf("%d",&s);
	spfa(s);
	for(i=1;i<=n;i++)
	    printf("%d ",dist[i]);
	printf("\n");
 system("pause");
	return 0;
}
