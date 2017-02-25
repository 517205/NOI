#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],i,j,x=1;
	int n(int z[3][3]);
	printf("原数组：\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++,x++)
		{
			a[i][j]=x;
			printf("%d",a[i][j]);
		
		if(x%3==0)
			printf("\n");
		}
	//b[0][0]=n(a);
	printf("调换后：\n");
	n(a);
	/*for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			printf("%d",b[i][j]);
		printf("\n");
		*/
	return 0;
}

int n(int z[3][3])
{
	int i,j,a[3][3],x=1;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			a[i][j]=z[j][i];
			x++;
		}
	for(i=0;i<3;i++)
		
	{	for(j=0;j<3;j++)
		{
			printf("%d",a[i][j]);
		
		
		}
			printf("\n");
	}
	return(0);
}
