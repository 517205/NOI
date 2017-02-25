#include<stdio.h>

int main()
{
	int a[10][10];
	int i,j;
	printf("Ñî»ÔÈý½Ç£¨Ê®ÐÐ£©£º\n");
	for(i=0;i<10;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}



	for(i=2;i<10;i++)
	{
		for(j=1;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}




	for(i=0;i<10;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%5d ",a[i][j]);
		}
		printf("\n");
	}


    system("pause");
	return 0;
}
//#include<string.h>
//int n,m,k,w,x,y,z;
	/*int i,j,m=0,x=0;

	for(j=0;j<=9;j++)
	{
		for(i=m;i<10;i++)
		{
			a[i][x]=1+j;
			printf("%5d",a[i][x]);
		}
	
		x++;
		m++;
	}*//*	for(w=1;w<=10;w++)
		if(w%10==0) printf("\n");
	for(n=0,m=0;n<10;n++,m++)
		a[n][m]=1;
		printf("%5d",a[n][m]);
	for(k=0;k<10;k++)
		a[k][0]=1;
		printf("%5d",a[k][0]);
	printf("\n");*/
