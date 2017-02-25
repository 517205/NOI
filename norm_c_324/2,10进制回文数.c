#include<stdio.h>
#include<stdlib.h>
int a[100],b[100];
int main()
{
    int i,j,x,t,m,n;
    printf("0 ");
    for(i=1;i<=1000;i++)
    {
        x=i;t=0;
        while(x>0)
        {
            a[++t]=x%2;
            x=x/2;
        }
        for(j=1,m=1;j<=t/2;j++)
        {
            if(a[j]!=a[t-j+1]) m=0;
        }
        x=i;t=0;
        while(x>0)
        {
            a[++t]=x%10;
            x=x/10;
        }
        for(j=1,n=1;j<=t/2;j++)
        {
            if(a[j]!=a[t-j+1]) n=0;
        }
        if(n==1&&m==1) printf("%d ",i);
    }
    printf("\n");
    system("pause");
    return 0;
}
