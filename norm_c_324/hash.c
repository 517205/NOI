#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n;
    char s1[27];
    int hash[27]={0};
    scanf("%s",s1);
    n=strlen(s1);
    for(i=0;i<n;i++)
    {
        hash[s1[i]-64]++;
    }
    for(i=0;i<27;i++)
    {
    
        printf("%d",hash[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
