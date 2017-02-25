#include<stdio.h>
#include<string.h>
int t[10]={0};
int hash[270000]={0};
int target;
int a[10]={0};
// 0--12(start)  1--3  2--6  3--9
struct apple{
    int step,map[10],no,fa;
}que[270000];
int d[10][10]={{0,0,0,0,0,0,0,0,0,0},
               {0,1,1,0,1,1},
               {0,1,1,1},
               {0,0,1,1,0,1,1},
               {0,1,0,0,1,0,0,1},
               {0,0,1,0,1,1,1,0,1},
               {0,0,0,1,0,0,1,0,0,1},
               {0,0,0,0,1,1,0,1,1},
               {0,0,0,0,0,0,0,1,1,1},
               {0,0,0,0,0,1,1,0,1,1}};
void bfs()
{
    int head=0,tail=1,i,j,ii,jj,m[10]={0},newm[10],k,c;
    memcpy(&que[tail].map,&t,sizeof(t));
    while(head<tail){
        head++;
        for(k=1;k<=9;k++){
            memcpy(&m,&que[head].map,sizeof(m));
            for(i=1;i<=9;i++)
                m[i]=(m[i]+d[k][i])%4;
            c=four(m);
            if( judge(c) ){
                que[++tail].step=que[head].step+1;
                que[tail].no=k;
                que[tail].fa=head;
                memcpy(&que[tail].map,&m,sizeof(a));
                if(c==0){
                    int write[1000]={0};
                    int x=tail,z=0;
                    while(que[x].fa>0)
                    {
                        write[++z]=que[x].no;
                        x=que[x].fa;
                    }
                    for(i=z;i>=1;i--)
                        printf("%d ",write[i]);
                    return;
                }
            }
        }     
    }  
}
int main()
{
    int i,j;
    for(i=1;i<=9;i++)
        scanf("%d",&t[i]);
    target=four(t);
    judge(target);
    bfs();
//    for(i=2;i<=10;i++)
//    {
//        for(j=1;j<=9;j++)
//            printf("%d ",que[i].map[j]);
//        printf("\n");
//    }
    printf("\n");
    system("pause");
    return 0;
}
int four(int aa[])
{   int d[]={0,65536,16384,4096,1024,256,64,16,4,1};
    int i,k=1,x=0;
    for(i=1;i<=9;i++)
        x+=aa[i]*d[i];
    return x;
}
int judge(int x)
{
    if(hash[x]==0)
    {
        hash[x]++;
        return 1;
    }
    else return 0;
}
