#include<stdio.h>
int main()
{
	int a;
	printf("输入一个年份:");
	scanf("%d,\n",&a);
	if(a%4==0)
	{
		if(a%100==0)
		{
			if(a%400==0)
				printf("这个年份是闰年\n");
			else
				printf("这个年份不是闰年\n");
		}	
		else
			printf("这个年份是闰年\n");
	}
	else
		printf("这个年份不是闰年\n");
	return 0;
}

