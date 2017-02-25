#include<stdio.h>
int dx[4]={ 1 ,0,-1, 0};
int dy[4]={ 0 ,-1,0 ,1};
int jc[11]={0,40320,5040,720,120,24,6,2,1,1};
int a[4][4]={0},m[4][4]={0},tt[4][4]={0};
int c=0;
int hash[370000]={0};
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
        {
            que[tail].map[i][j]=m[i][j];
            tt[i][j]=m[i][j];
        }    
    judge();    
            
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
                
                if(  judge() )
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

int  judge()
{
    int x=0,i,j,k=0;
    int b[10];
    b[1]=tt[1][1]; b[2]=tt[1][2]; b[3]=tt[1][3];
    b[4]=tt[2][1]; b[5]=tt[2][2]; b[6]=tt[2][3];
    b[7]=tt[3][1]; b[8]=tt[3][2]; b[9]=tt[3][3];
    for(i=1;i<=9;i++)
    {
        for(j=i+1;j<=9;j++)
        {
            if(b[i]>=b[j]) k++;
        }
        x=x+jc[i]*k;
        k=0;
    }
    if(hash[x]==0)
    {
        hash[x]++;
        //printf("#");
        return 1;
    }
    else
    {
        hash[x]++;
        //printf("-");
        return 0;
    }
}
int t(int n)
{
        if(n==0) return 1;
        else return n*t(n-1);
}

