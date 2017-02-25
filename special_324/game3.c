#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=1,x=1,y=40;
    while(1)
    {
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
    }
    return 0;
}
