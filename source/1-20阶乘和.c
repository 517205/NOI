#include<stdio.h>
int main()
{
	long i,a=1,j=20,x=0;
	printf("1!+2!+......+20!=");
	for(j=20;j>=1;j--)
	{


	
		for(i=1;i<=j;i++)
		{
			a=a*i;
		}

		x=x+a;

		a=1;

	}
	printf("%d\n",x);
	return 0;
}
        
