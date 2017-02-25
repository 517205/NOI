#include<iostream>
#include<cstdio>
using namespace std;

int s,t,l,M,finalans=150;
int m[150]={0};

void write(int ans)
{
	if(ans<finalans)
		finalans=ans;
	if(ans==0) return;
}

int judge(int c)
{
	for(int j=1;j<=M;j++)
		if(m[j]==c) return 1;
	return 0;
}

void bfs(int ans,int frog)
{
	int newfrog,flag,i;
	if(frog+s>=l) write(ans);
	for(i=t;i>=s;i--)
	{
		newfrog=frog+i;
		if(judge(frog)) 
		{
			ans++;
			flag=1;
		}
		else flag=0;
		if(ans<finalans)
			bfs(ans,newfrog);
		if(flag==1) ans--;
		frog=newfrog-i;
	}
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("river.in","r",stdin);
	fout=freopen("river.out","w",stdout);
	
	scanf("%d%d%d%d",&l,&s,&t,&M);
	int i;
	for(i=1;i<=M;i++)
		scanf("%d",&m[i]);
/*
	printf("%d %d %d %d\n",l,s,t,M);
	for(i=1;i<=M;i++)
		printf("%d",m[i]);
*/
	bfs(0,0);
	printf("%d\n",finalans);
	fclose(fin);fclose(fout);
	return 0;
}
