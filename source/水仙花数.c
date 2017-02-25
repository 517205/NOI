#include<stdio.h>
int main()
{
	int a,b,c,s,x;
	printf("水仙花数有：\n");
    for(x=100;x<=999;x++)
	{
		a=(x-x%100)/100;
		b=(x%100-x%10)/10;
		c=x%10;
		if((a*a*a+b*b*b+c*c*c)==x)
			printf("%d\t",x);
	}
	printf("\n");
	return 0;
}