#include<stdio.h>
int dx[4]={ 1 ,0,-1, 0};
int dy[4]={ 0 ,-1,0 ,1};
int a[4][4]={0},m[4][4]={0},tt[4][4]={0};
int c=0;
struct apple
{
    int x,y,step,map[4][4];
}que[370000];

void bfs(int xx,int yy)
{
    int head=0,tail=1,x,y,newx,newy,i,j,k,b,temp,ii,jj;
    que[tail].x=xx; que[tail].y=yy; que[tail].step=0;
    for(i=1;i<4;i++)
        for(j=1;j<4;j++)
            que[tail].map[i][j]=m[i][j];
            
    while(head<tail)
    {
        head++;
        x=que[head].x; y=que[head].y;
        
        for(k=0;k<4;k++)
        {
            newx=x+dx[k]; newy=y+dy[k]; c=0;
            
            if(newx>0 && newx<4 && newy>0 && newy<4) 
            {
                for(ii=1; ii<4; ii++)
                    for(jj=1; jj<4; jj++)
                        tt[ii][jj]=que[head].map[ii][jj];
                tt[x][y]=tt[newx][newy];
                tt[newx][newy]=0;     
                
                if(  judge(tail) )
                {
                    que[++tail].x=newx;que[tail].y=newy;
                    que[tail].step=que[head].step+1;
                    for(ii=1; ii<4; ii++)
                        for(jj=1; jj<4; jj++)
                            que[tail].map[ii][jj]=tt[ii][jj];
                
                    b=1;
                    for(i=1;i<4;i++)
                        for(j=1;j<4;j++)
                            if(que[tail].map[i][j]!=a[i][j]) {b=0; break;} 
                    if(b==1)
                    {
                        printf("%d\n",que[tail].step);
                        return;
                    }
                    //judge&output
               }
            }
        }
    }
}

int main()
{
    int i,j,x,y;
    for(i=1;i<4;i++)
     for (j=1; j<4; j++)
      {
        scanf("%d",&m[i][j]);
        if (m[i][j]==0)  {x=i; y=j;}
      }   
    for(i=1;i<4;i++)
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        
        
        
    bfs(x,y);
    system("pause");
    return 0;
}

int  judge(int aa)
{
    int j,i,k,flag1;
    for(k=1;k<=aa;k++)
    {
        flag1=1;
        for(i=1;i<4;i++)
        {   
            for(j=1;j<4;j++)    
               if(tt[i][j]!=que[k].map[i][j])
                {
                    flag1=0;break;
                }
            if (flag1==0) break;    
        }
        if (flag1==1) return 0;//same;
    }
    return 1;
}
/*for(i=1;i<4;i++)
    scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
*/
