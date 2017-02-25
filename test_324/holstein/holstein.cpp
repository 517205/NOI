#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int v,g,ans=0,best=210000;
int f[20]={0};
int vol[30],s1[30],s2[30];
int w[30][30];
int ok()
{
	int i;
	for(i=0;i<=29;i++)
		if(vol[i]>0) return 0;
    printf("ok\a");
    system("pause");
	return 1;
}

void update()
{
	int i;
	for(i=0;i<=29;i++)
		s2[i]=s1[i];
//    memcpy(&s1,&s2,sizeof(s1));
    for(i=0;i<=29;i++)
        printf("%d   ",s2[i]);
    printf("\a\n");
    system("pause");
	best=ans;
}

void dfs(int s,int dep)
{
	int i,j;
	if(ok() && dep<best) update();

	if(dep+1<best)
	{
		for(i=s+1;i<=g;i++)
			if(dep+1<best)
			{
				for(j=1;j<=v;j++) vol[j]-=w[i][j];
				s1[++ans]=i;
				dfs(i,dep+1);
				for(j=1;j<=v;j++) vol[j]+=w[i][j];
				ans--;
			}
	}
}

int main()
{
	FILE *fin,*fout;
	fin=fopen("holstein.in","r");
	fout=fopen("holstein.out","w");
	
	fscanf(fin,"%d",&v);
	int i,j;
	for(i=1;i<=v;i++)
		fscanf(fin,"%d",&vol[i]);
	fscanf(fin,"%d",&g);
	for(i=1;i<=g;i++)
		for(j=1;j<=v;j++)
			fscanf(fin,"%d",&w[i][j]);
			
/*			
    for(i=0;i<=29;i++)
    {
        for(j=0;j<=29;j++)
            fprintf(fout,"%d ",w[i][j]);
        fprintf(fout,"\n");
    }
    system("pause");  
    return 0;
*/  
	for(i=1;i<=g;i++)
	{
		for(j=1;j<=v;j++) vol[j]-=w[i][j];
		s1[++ans]=i;
		dfs(i,1);
		for(j=1;j<=v;j++) vol[j]+=w[i][j];
		ans--;
	}
	fprintf(fout,"%d\n",best);
	for(i=1;i<=best;i++)
		fprintf(fout,"%d ",s2[i]);
	fclose(fin);fclose(fout);
	return 0;
}
