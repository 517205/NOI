#include<stdio.h>
int dx[9]={0,1,2,-1,-2,-2,-1,1,2};
int dy[9]={0,2,1,2,1,-1,-2,-2,-1};
int a[11][11]={0};
int n,x,y,newx,newy,ans=0;
int dep;
void write()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d  ",a[i][j]);
        printf("\n");
    }
    
    ans++;
    printf("----------------------------\n");
}

void search(int dep,int x,int y)
{
    int i,j,newx,newy;
    if(dep==n*n){write();}
    for(i=1;i<=8;i++)
    {
        newx=x+dx[i];
        newy=y+dy[i];
        if(newx>=1 && newx<=n && newy>=1&& newy<=n&& a[newx][newy]==0) 
        {
           a[newx][newy]=dep+1;
           search(dep+1,newx,newy);
           a[newx][newy]=0;
        }
    }
}   
int main()
{
    int i,j;
    scanf("%d%d%d",&n,&x,&y);
    a[x][y]=1;
    search(1,x,y);
    printf("\n%d\n",ans);
    system("pause");
    return 0;
}
