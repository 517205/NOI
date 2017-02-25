#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

char map[11][11];
char map2[11][11];
int N;
int x;
int judge4()//OK remain
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(map[i][j]!=map2[i][j])
				return 0;
	return 1;
}
int judge3()//upside down
{
	int i,j;
	int tx,ty;
	int xx,yy;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			tx=x-i;
			ty=x-j;
			xx=x+tx;
			yy=x+ty;
			if(map[i][j]!=map2[xx][yy])
				return 0;
		}
	return 1;
}
int judge2()//OK inverse clock 90 
{
//	printf("#judge2:\n");
	int i,j;
	int tx,ty;
	int xx,yy;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			tx=x-i;
			ty=x-j;
			xx=x+ty;
			yy=x-tx;
	//		printf("tx=%d ty=%d xx=%d yy=%d map[i][j]=%c map2[xx][yy]=%c\n",tx,ty,xx,yy,map[i][j],map2[i][j]);
			if(map[i][j]!=map2[xx][yy])
				return 0;
		}
	return 1;
}
int judge1()//OK clock 90
{
//	printf("#judge1:\n");
	int i,j;
	int tx,ty;
	int xx,yy;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			tx=x-i;
			ty=x-j;
			xx=x-ty;
			yy=x+tx;
	//		printf("tx=%d ty=%d xx=%d yy=%d map[i][j]=%c map2[xx][yy]=%c\n",tx,ty,xx,yy,map[i][j],map2[i][j]);
			if(map[i][j]!=map2[xx][yy])
				return 0;
		}
	return 1;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("changing.in","r",stdin);
	fout=freopen("changing.out","w",stdout);
	
	scanf("%d",&N);
	x=(N+1)/2;
//	printf("x=%d\n\n",x);
	int i,j;
	for(i=1;i<=N;i++)
	{	
		scanf("\n");
		for(j=1;j<=N;j++)
		scanf("%c ",&map[i][j]);
	}
	for(i=1;i<=N;i++)
	{	
		scanf("\n");
		for(j=1;j<=N;j++)
		scanf("%c ",&map2[i][j]);
	}
	
	if(judge1())
	{
		printf("1");
		fclose(fin);fclose(fout);
		return 0;
	}
	else if(judge2())
	{
		printf("2");
		fclose(fin);fclose(fout);
		return 0;
	}	
	else if(judge3())
	{
		printf("3");
		fclose(fin);fclose(fout);
		return 0;
	}	
	else if(judge4())
	{
		printf("4");
		fclose(fin);fclose(fout);
		return 0;
	}
	printf("5");
	
	
	
	
	
	
	
	
	
/*	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			printf("%c ",map2[i][j]);
		printf("\n");
	}
	*/
	
	
	fclose(fin);fclose(fout);
	return 0;
}
