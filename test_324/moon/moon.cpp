#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define M  1000
int n,p,i,w;
int l,x,y,father[M],h[M],h1,h2;



int find(int v)
{
	int f;
	if(v==father[v])
	{
		w=h[v];
		return v;
	}
	f=father[v];
	father[v]=find(father[v]);
	h[v]=h[v]+h[f];
//	h[v]+=l[i];
	w=h[v];
	return father[v];
}

int main()
{
	freopen("moon.in","r",stdin);
	freopen("moon.out","w",stdout);
	scanf("%d%d",&n,&p);
	int temx,temy,minhigh=2100000000;
	for(i=1;i<n;i++)
		father[i]=i;
	for(i=1;i<=p;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		temx=find(x);h1=w;
		temy=find(y);h2=w;
		if(temx==temy)
		{
			if(abs(h[x]-h[y])!=l)
			{
				printf("-1\n");
				
				return 0;
			}
		}
		father[temy]=temx;
		h[temy]=h1+l-h2;
	}
	int ancestor=find(1);
	for(i=1;i<=n;i++)
		if(find(i)!=ancestor)
		{
			printf("-1");
			return 0;
		}
	for(i=1;i<=p;i++)
	    if(minhigh>h[i])
	        minhigh=h[i];
	for(i=1;i<=p;i++)
	    h[i]=h[i]-minhigh;
	for(i=1;i<=p;i++)
	    printf("%d\n",h[i]);
	return 0;
}
