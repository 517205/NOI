#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int d,b,i,x;
    scanf("%d",&x);
    srand((unsigned)time(0));
    for(i=1;i<=x;i++)
    {
    d=rand();
    b=d%10;
    printf("%d\n",b);
    }
    system("pause");
    return 0;
}
