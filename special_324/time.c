#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
int main()
{
    time_t start,end;
    printf("计时开始");
    system("pause");
    int t0=(double)clock()/CLOCKS_PER_SEC;
    while(1)
    {
    printf("%2f\n",(double)clock()/CLOCKS_PER_SEC-t0);
    system("cls");
    }
    system("pause");
    return 0;
}
