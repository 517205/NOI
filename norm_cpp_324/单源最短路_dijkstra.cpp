#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define maxn 100
int map[maxn][maxn]={0};
int vist[maxn]={0};
int dist[maxn]={0};
int n,e,min,w,s;
int main()
{
	int i,j,x,y,z;
	scanf("%d%d",&n,&e);//n=dot e=side
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z;
		map[y][x]=z;
	}//make map
	memset(dist,127,sizeof(dist));//max
	scanf("%d",&s);//start
	dist[s]=0;
	for(i=1;i<n;i++)//1¡«n-1
	{
		int min=21000000;
		for(j=1;j<=n;j++)
			if(dist[j]<min && vist[j]==0)
			    {
					min=dist[j];
					w=j;
				}
		vist[w]=1;
		for(j=1;j<=n;j++)
			if(map[j][w]!=0 && vist[j]==0 && dist[j]>map[w][j]+dist[w])
				dist[j]=map[w][j]+dist[w];
	}
	for(i=1;i<=n;i++)
	{
	    if(dist[i]!=2139062143)
			printf("%d ",dist[i]);
		else printf("max ");
	}
	printf("\n");
	system("pause");
	return 0;
}
