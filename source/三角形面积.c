#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,s,area;
	printf("输入三条边长度：");
	scanf("%f,%f,%f",&a,&b,&c);
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("a=%f\tb=%f\tc=%f\n",a,b,c);
	printf("area=%f\ncm2",area);
	return 0;
}