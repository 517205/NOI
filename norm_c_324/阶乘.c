#include<stdio.h>
int t1(int n)
{
        if(n==0) return 1;
        else return n*t1(n-1);
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",t1(x));
    system("pause");
    return 0;
}
 
