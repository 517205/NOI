#include<stdio.h>
int main()
{
	float f,c;
	printf("������һ�������¶ȣ�");
	scanf("%f,\n",&f);
	//c=f*(5/9)-32*(5.0/9);
	c=(f-32)*(5.0/9);
	printf("�����¶���: %f \n",c);

	return 0;
}

