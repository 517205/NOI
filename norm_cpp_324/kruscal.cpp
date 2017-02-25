#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1000],x[1000],y[1000];
int fa[1000];
int n,e;

int find(int v)
{
    if(v==fa[v]) return v;
    fa[v]=find(fa[v]);
    return fa[v];
}

void ss()
{
	int i,j,t;
	for(i=1;i<n;i++)
		for(j=i;j<=n;j++)
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}
}
int main()
{
    int i,sum=0;
    scanf("%d%d",&n,&e);//e=side,n=point
    for(i=1;i<=999;i++)
    	fa[i]=i;
    for(i=1;i<=e;i++)
    	scanf("%d%d%d",&x[i],&y[i],&a[i]);
    ss();
    for(i=1;i<=e;i++)
    {
		int xx=find(x[i]),yy=find(y[i]);
		if(xx==yy) continue;
		else
		{
			sum+=a[i];
			printf("%d %d\n",x[i],y[i]);
			fa[xx]=yy;	
		}
	}
    printf("\nsum=%d\n",sum);
    system("pause");
    return 0;
}
