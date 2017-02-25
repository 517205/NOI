#include<stdio.h>
int main()
{
	int a,b,c;
	int max(int x,int y);
	printf("please enter two integer number:");
	scanf("%d,%d",&a,&b);
	c=max(a,b);
	printf("max is %d\n",c);
	return 0;
}
int max(int x,int y)
{
	int z;
	z=x>y? x:y;
	return(z);
}