#include<stdio.h>
int main()
{
	int i,j,row=0,comul=0,max;
	int a[3][4]={{1,2,300,4},{9,8,7,6},{-10,10,-5,2}};
	max=a[0][0];
	for(i=0;i<=2;i++)
		for(j=0;j<=3;j++)
			if(a[i][j]>max)
			{
				max=a[i][j];
				row=i;
				comul=j;
			}
	printf("max=%d\nrow=%d\ncomul=%d\n",max,row,comul);
	return 0;
}