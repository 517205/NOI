#include<stdio.h>
int n,e;
int map[100][100]={0};
int vist[100]={0};
int que[100]={0};
void bfs(int x)
{
    int head=0,tail=1;
    int v,i;
    que[tail]=x;
    vist[x]=1;
    printf("%d",x);
    while(head<tail)
    {
        head++;
        v=que[head];
        for(i=1;i<=n;i++)
            if(map[v][i]!=0&&vist[i]==0)
                {
                    tail++;
                    que[tail]=i;
                    vist[i]=1;
                    printf("%d",i);
                }
    }
}

int main()
{
    int i,j,x,y;
    scanf("%d%d",&n,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
        map[y][x]=1;
    }
    for(i=1;i<=n;i++)
        if(vist[i]==0)
            bfs(i);
    printf("\n");
    system("pause");
    return 0;
}
