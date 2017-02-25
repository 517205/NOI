#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,i,j,w,m=1,n;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
	   for (j=1; j<=n-i; j++)
	       printf(" ");
	   for (j=1; j<=2*i-1; j++)
	   {
	       printf("%d",m);
	       m=m+2;
	       if (m>9)m=1;
	   }    
	   printf("\n");
	}
	system("pause");
	return 0;
}
