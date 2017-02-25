#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int a[100]={0,523,587,659,784,880,980,1060};
void sound(int x,int y)
{
	sleep(50);
	Beep(a[x],y);
	sleep(50);
}
int main()
{
	FILE *fin;
	fin=freopen("sound.in","r",stdin);
	srand((unsigned)time(NULL));
	int t,i,tt,a;
	printf("music!\n");
//	printf("Time:t(ms)");
	scanf("%d",&t);
	
	while(scanf("%d",&tt) && tt!=-1)
	{
		sound(tt,t);
	}
	sleep(1000);
	printf("random sound!\n"); 
	while(1)
	{
		a=rand();
		a=a%7+1;
		printf("%d ",a);
		sound(a,t);
	}
	sleep(1000);
	
	fclose(fin);
	return 0; 
}
/*	
	Beep(523,1000);   // 参数 是 （音调，时间）
	Beep(587,1000);
	Beep(659,1000);
	Beep(698,1000);
	Beep(784,1000);
	Beep(880,1000);
	Beep(980,1000);
	Beep(1060,1000);
	Beep(10000,500);
*/
