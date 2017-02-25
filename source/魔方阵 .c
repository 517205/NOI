#include<stdio.h>
int main()
{
	int a[5][5];
	int i,j,x=1;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			a[i][j]=0;
	for(i=2,j=0;i>=0;j++,i--,x++)
		a[i][j]=x;

	for(i=3,j=1;i>=1;j++,i--,x++)
		a[i][j]=x;

	for(i=4,j=2;i>=2;j++,i--,x++)
		a[i][j]=x;
	a[2][3]=a[2][0];
	a[3][2]=a[0][2];
	a[1][2]=a[4][2];
	a[2][4]=a[2][1];
	a[2][0]=0;
	a[0][2]=0;
	a[4][2]=0;
	a[2][4]=0;

	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*	for(i=0;i<5;i++)
		a[i][0]=0;
		a[i][4]=0;
	for(j=0;i<5;j++)
		a[0][j]=0;
		a[4][j]=0;*/