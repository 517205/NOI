#include<stdio.h>
int main()
{
	float f,c;
	printf("请输入一个华氏温度：");
	scanf("%f,\n",&f);
	//c=f*(5/9)-32*(5.0/9);
	c=(f-32)*(5.0/9);
	printf("摄氏温度是: %f \n",c);

	return 0;
}

