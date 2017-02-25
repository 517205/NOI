#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

//int p0[4501]={0},p[4501]={0};
//int a[20000009]={0};
int m,n;
/*
void pp()
{
	int i,j=0,k,l=1;
	for(i=3;i<=4500;i=i+2)
		p0[i]=1;
	for(i=1;i<=67;i++)
	{
		j++;
		for(j;p0[j]==0;j++){}
		for(k=j*2;k<=4500;k=k+j)
			p0[k]=0;
	}
	for(i=1;i<=4500;i++)
		if(p0[i]==1) p[l++]=i;
	p[0]=2;

}
*/
int g(int x)
{
	int s=0,i;
	for(i=1;i<=x && i<=4501;i++)
		if(x%i==0)
			s++;
	for(i=2;i<=x && i<=4501;i++)
		while(x%i==0)
			x=x/i;
	if(x!=1) return s+1;//big prime
	return s;
}
int judge(int x)
{
	int c=g(x);
	for(int i=2;i<x;i++)
	if(g(i)>=c) return 0;
	return 1;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("iprime.in","r",stdin);
	fout=freopen("iprime.out","w",stdout);
	
//	pp();
	int i,j,sum,first=1;
//	printf("%d\n\n",g(599999));
	scanf("%d%d",&m,&n);
	for(i=1;i<=100000;i++)
		printf("g%d=%d\n",i,g(i));
//	sort(a+1,a+m);//a+m-1
	for(i=m;i<=n;i++)
	{
		if(judge(i) && first==0)
			printf(",%d",i);
		if(judge(i) && first==1)
		{
			printf("%d",i);
			first=0;
		}
	}
	fclose(fin);fclose(fout);
	return 0;
}
