#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=1,x=0,y=0,j=1,k;
    for(i=5;i>=0;i--)
    {
        printf("平抛：%d\n请把窗口放到最大",i);
        sleep(1000);
        system("cls");
    }
    for(k=1;k<=8;k++)
    {
    for(i=1;i<=x;i++)
        for(j=1;j<=x;j++)
            printf("\n");
    for(i=1;i<=y;i++)
        printf(" ");
    printf("o");
    x++;y=y+10;
    sleep(1000);
    system("cls");
    }
    for(i=1;i<=x-1;i++)
        for(j=1;j<=x-1;j++)
            printf("\n");
    for(i=1;i<=y-7;i++)
        printf(" ");
    printf("end");
    sleep(1000);
    return 0;
}
/*
    while(1)
    {
    for(i=1;i<=x;i++) printf(" ");
    printf("2025");
    sleep(y);
    //if(y>1) y--;
    system("cls");
    if(x<76)x++;
    else break;
    }
    while(1)
    {
    for(i=x;i>=1;i--) printf(" ");
    printf("2025");
    sleep(y);
    //if(y>1) y--;
    system("cls");
    if(x>1)x--;
    else break;
    //printf("\n %c",16);
    //sleep(300);
    //system("cls");
    }
    
    */
