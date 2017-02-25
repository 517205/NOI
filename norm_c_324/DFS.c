#include<stdio.h>
int n,e;
int map[100][100]={0};
int vist[100]={0};
void dfs(int x)
{
     int i;
     printf("%d",x);
     vist[x]=1;
     for(i=1;i<=n;i++)
         if(map[x][i]!=0&&vist[i]==0)
             dfs(i);
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
    dfs(1);
    for(i=1;i<=n;i++)
        if(vist[i]==0)
            dfs(i);
    printf("\n");
    system("pause");
    return 0;
}


                 
                      

