#include<stdio.h>
int main()
{
	int a;
	printf("����һ�����:");
	scanf("%d,\n",&a);
	if(a%4==0)
	{
		if(a%100==0)
		{
			if(a%400==0)
				printf("������������\n");
			else
				printf("�����ݲ�������\n");
		}	
		else
			printf("������������\n");
	}
	else
		printf("�����ݲ�������\n");
	return 0;
}

