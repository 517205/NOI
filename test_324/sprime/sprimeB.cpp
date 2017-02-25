#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a[5]={0,2,3,5,7};
int b[6]={0,1,3,5,7,9};
int aa[10000]={0};
int n,X=1;


int judge(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

void dfs(int k,int step)
{
	int j,c=1;
	if(step==n)
	{
		aa[X++]=k;
		return;
	}
	for(j=1;j<=5;j++)
		if(judge(k*10+b[j]))
			dfs(k*10+b[j],step+1);
}

int main()
{
	FILE *fin,*fout;
	fin=fopen("sprime.in","r");	
	fout=fopen("sprime.out","w");
	
	fscanf(fin,"%d",&n);
	int i;
	for(i=1;i<=4;i++)
		dfs(a[i],1);
	for(i=1;aa[i]!=0;i++)
		fprintf(fout,"%d\n",aa[i]);
	fclose(fin);fclose(fout);
	return 0;
}	

