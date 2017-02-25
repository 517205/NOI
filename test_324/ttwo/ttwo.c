#include<stdio.h>
int hash[10][10][4][10][10][4]={0};//a,b
int a1[10][10]={0};//a[x][y]
char s[10][10];
struct pp
{
	int x;
	int y;
	int d;
};
/*    0
      ¡ü
  3 ¡û  ¡ú1
      ¡ý
	  2
*/
void go(struct pp *p)
{
	int xx,yy;
	xx=p->x;
	yy=p->y;
	
	if(p->d==0)
	{
		if(xx-1>=0 && a1[xx-1][yy]==0) p->x=p->x-1; 
		else p->d=1;
		return;
	}
	if(p->d==1)
	{
		if(yy+1<=9 && a1[xx][yy+1]==0) p->y=p->y+1;
		else p->d=2;
		return;
	}
	if(p->d==2)
	{
		if(xx+1<=9 && a1[xx+1][yy]==0) p->x=p->x+1;
		else p->d=3;
		return;
	}
	if(p->d==3)
	{
		if(yy-1>=0 && a1[xx][yy-1]==0) p->y=p->y-1;		
		else p->d=0;
		return;
	}	
}
int main()
{
	FILE *fin,*fout;
	fin=fopen("ttwo.in","r");
	fout=fopen("ttwo.out","w");
	


	int step=0,i,j;
	struct pp a,b;
	a.d=0;b.d=0;
	
	for(i=0;i<=9;i++)
		fscanf(fin,"%s",s[i]);
		
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			if(s[i][j]=='.') a1[i][j]=0;
			if(s[i][j]=='*') a1[i][j]=1;
			if(s[i][j]=='F') {a.x=i;a.y=j;a1[i][j]=0;}
			if(s[i][j]=='C') {b.x=i;b.y=j;a1[i][j]=0;}
		}
	hash[a.x][a.y][a.d][b.x][b.y][b.d]++;	
	while(1)
	{
		go(&a);go(&b);
		if(hash[a.x][a.y][a.d][b.x][b.y][b.d]==0)
		      hash[a.x][a.y][a.d][b.x][b.y][b.d]=1;
		else {  fprintf(fout,"0"); break;   }
		
		if(a.x==b.x&&a.y==b.y)
		{
			fprintf(fout,"%d",step+1);
			break;
		}
		step++;
	}
	
	
	fclose(fin);fclose(fout);
	return 0;
}	
