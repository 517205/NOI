#include<stdio.h>
int main()
{
	int a,b,c,sum,s;
	printf("请输入3个数\n");
	printf("第一个:");
	scanf("%d,\n",&a);
	printf("请输入第二个数：");
	scanf("%d,\n",&b);
	//scanf("%d\n",&b);
    printf("请输入第三个数:");
    scanf("%d,\n",&c);
	sum=a+b+c;
	s=a*b*c;
    printf("a+b+c=%d\n",sum);
	printf("a*b*c=%d\n",s);
	return 0;
}

