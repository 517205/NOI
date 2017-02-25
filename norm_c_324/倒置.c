#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,t;
    char s1[20];
    scanf("%s",s1);
    n=strlen(s1);
    for(i=0;i<=n/2;i++)
    {
        t=s1[i];
        s1[i]=s1[n-i-1];
        s1[n-i-1]=t;
    }
    printf("%s\n",s1);
    system("pause");
    return 0;
}
