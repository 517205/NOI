#include<stdio.h>
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char map[1001][1001];   //1==can`t  0==can
int j,i,k,n;
int x1,x2,y11,y2;
struct apple
{
    int x,y,step;
}que[1000001];
void bfs(int xx,int yy)
{
    int head=0,tail=1,x,y,newx,newy;
    que[tail].x=xx; que[tail].y=yy; map[xx][yy]='1';
    que[tail].step=0;
    while(head<tail)
    {
        head++;
        x=que[head].x; y=que[head].y;
        for(i=0;i<4;i++)
        {
            newx=x+dx[i]; newy=y+dy[i];
            if(newx>0 && newx<=n && newy>=0 && newy<n && map[newx][newy]=='0')
            {
                tail++;
                que[tail].x=newx;
                que[tail].y=newy;
                que[tail].step=que[head].step+1;
                map[newx][newy]='1';
                if(newx==x2 && newy==y2)
                {
                    printf("%d\n",que[tail].step);
                    return;
                }
            }
        }
    }
}
/*
 0 1 2 3 4....
1* * * * *
2* * * * *
3* * * * *
...
*/
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%s",map[i]);
    scanf("%d%d",&x1,&y11);
    scanf("%d%d",&x2,&y2);
    y11--;
    y2--;
    bfs(x1,y11);
    system("pause");
    return  0;
}
