#include<stdio.h>
int main()
{
	int a,b,c,sum,s;
	printf("������3����\n");
	printf("��һ��:");
	scanf("%d,\n",&a);
	printf("������ڶ�������");
	scanf("%d,\n",&b);
	//scanf("%d\n",&b);
    printf("�������������:");
    scanf("%d,\n",&c);
	sum=a+b+c;
	s=a*b*c;
    printf("a+b+c=%d\n",sum);
	printf("a*b*c=%d\n",s);
	return 0;
}

