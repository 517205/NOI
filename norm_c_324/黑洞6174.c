#include<stdio.h>
#include<stdlib.h>
int a[5];
int k,j,u,max,min,n1,n,b=0;
int main()
{
    int i,j,x=1,y,n,m,z;
    for(x=1000;x<=9999;x++)
    {
    if(x%1111!=0) 
    {
        y=x;n=x;z=1;m=0;b=x;
        while(z!=0)
        {
           if(b!=6174) {t1(n);
                        n=b;
           				m=m+1;}
           else z=0;
        }
        printf("%d:%d\n",x,m);
        n=0;b=0;m=0;
    }
            
    }
    //printf("\n");
    system("pause");
    return 0;
}
int t1(int n)
{
    a[1]=n/1000;
    a[2]=(n%1000)/100;
    a[3]=(n%100)/10;
    a[4]=n%10;
    for(k=1;k<=4;k++)
        for(j=k;j<=4;j++)
        {
            if(a[k]<a[j])
            {
               u=a[k];
               a[k]=a[j];
               a[j]=u;
            }
        }
    max=1000*a[1]+100*a[2]+10*a[3]+a[4];
    min=1000*a[4]+100*a[3]+10*a[2]+a[1];
    b=max-min;
    return b;
}
                
    





















