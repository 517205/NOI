#include<stdio.h>
#include<stdlib.h>
int main()
{
     char s1[50],x=65;
     int i,n;
     int hash[27]={0};
     scanf("%s",s1);
     n=strlen(s1);
     for(i=0;i<n;i++)
     {
          printf("%c",s1[i]);
          if(s1[i]==65) {printf(" ");}
               
     }
     printf("\n");
     for(i=0;i<n;i++)
     {
          hash[s1[i]-64]++;
     }
     for(i=1;i<27;i++,x++)
     {
          printf("%c:%d\n",x,hash[i]);
     }
     system("pause");
     return 0;
}
     
     
