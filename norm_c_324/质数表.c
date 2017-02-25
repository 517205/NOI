#include<stdio.h>
#include<math.h>
#define A 1000000
int a[A]={0};
int a1[A]={0};
int main()
{
    int i=0,j=0,k=1,t=1,m=0,x;
    //scanf("%d",x);
    printf("please wait......\n");
    for(i=2;i<A;i++)
        {a[i]=1;}
    a[1]=0;a[0]=0;
    for(i=1;i<sqrt(A)+1;i++)
    {
        j=j+1;
        for(j=m++;a[j]==0;j++){}
        for(k=2*j;k<A;k=k+j)
            a[k]=0;
    } 
    for(i=1;i<A;i++)
    {
        if(a[i]!=0)
        {
            a1[t++]=i;
        }
    }
    for(i=1;i<A,a1[i]!=0;i++)
    {
        printf("%d  ",a1[i]);
        if(i%2000==0){ printf("\n"); system("pause"); printf("\n"); }
    }
    printf("\n%d\n",i);
    system("pause");
    return 0;
}


















