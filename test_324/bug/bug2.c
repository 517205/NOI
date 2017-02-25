#include<stdio.h>
//0=same,1=differ
int f[2005],r[2005];
int fs(int i)
{
if(f[i]==i)
   return i;
int t=f[i];
f[i]=fs(f[i]);                //路径压缩技术，使f[i]直接指向最新的根节点
//计算相对于新的父节点（即根）的秩，r[t]是老的父节点相对于新的父节点（即根）的秩
//，r[i]是i元素相对于老的父节点的秩，
//类似于物理里的相对运动，得到的r[i]就是相对于新的父节点（即根）的秩。而且这个递归调用不会超过两层。
r[i]=(r[t]+r[i])%2; 
return f[i];
}

void un(int x,int y)//union
{
int a=fs(x),b=fs(y);
f[a]=b;
r[a]=(r[y]-r[x]+1)%2;       //r[a]+r[x]与r[y]相对于新的父节点必须相差1个等级，因为他们不是gay
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cases,n,m,i,k,x,y;
	scanf("%d",&cases);
	for(k=1;k<=cases;k++)
	{
   		int flag=0;
   		scanf("%d %d",&n,&m);
   		for(i=1;i<=n;i++)
   		{
    		f[i]=i;
    		r[i]=0;
   		}
   for(i=1;i<=m;i++)
   {
    scanf("%d %d",&x,&y);
    if(fs(x)==fs(y))
    {
     if(r[x]!=(r[y]+1)%2)
      flag=1;
    }
    else
     un(x,y);
   }
   if(flag)
    printf("Scenario #%d:\nSuspicious bugs found!\n\n",k);
   else
    printf("Scenario #%d:\nNo suspicious bugs found!\n\n",k);
	
 
 
 //	system("pause");
 }
//system("pause");
return 0;
}
