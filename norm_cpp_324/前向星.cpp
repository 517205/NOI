#include<iostream>
#include<cstdio>
using namespace std;

struct apple
{
    int v,next;
}edge[1000];
int index[1000]={0};
int vist[1000];
void dfs(int a)
{
    int t,vv;

    vist[a]=1;
    t=index[a];
    while(t!=0)
    {
        vv=edge[t].v;
        if(vist[vv]==0)
        {
            dfs(vv);
            printf("%d ",vv);
        }
        t=edge[t].next;
    }
}
int main()
{
    int tot=1,n,e,x,y,c,i;
    scanf("%d%d",&n,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&x,&y);
        edge[tot].v=y;
        edge[tot].next=index[x];
        index[x]=tot++;
    }
    scanf("%d",&c);
    dfs(c);
    printf("\n");
    system("pause");
    return 0;
}

