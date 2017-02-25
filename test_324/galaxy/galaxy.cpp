#include<iostream>
#include<cstdio>
//#include<stdio.h>
#include<cmath>
#include<cstdlib>
using namespace std;

#define maxn 30000
int father[maxn],count[maxn],before[maxn];
int t;
int getfather(int v)
{
	int f;
	if(father[v]==v) return v;
	f=father[v];
	father[v]=getfather(father[v]);
	before[v]=before[v]+before[f];
	return father[v];
}

void merge(int x,int y,int count[])
{
	int i=getfather(x);
	int j=getfather(y);
	father[i]=j;
	
	before[x]+=count[y];
	count[y]+=count[x];
}

void ask(int x,int y)
{  
	if(getfather(x)!=getfather(y))printf("-1\n");
		else  if(before[x]>before[y]) printf("%d\n",before[x]-before[y]-1);
		    else printf("%d\n",before[y]-before[x]-1);
}

int main()
{
	int a,b,k;
	char aa;
	int count[30000]={0};
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out", "w",stdout);
	scanf("%d\n",&t);
	int i;
	for(i=1;i<29999;i++)
	{
		father[i]=i;
		count[i]=1;
		before[i]=0;
	}
	for(k=1;k<=t;k++)
	{
		scanf("%c ",&aa);
		scanf("%d%d\n",&a,&b);
		if(aa=='M') {merge(a,b,count);}
			else if(aa=='C') {ask(a,b);}
	}
	//system("pause");
	return 0;
}
