#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,m,n,k=-1;
	char s[60],a[60],t;
	//scanf("%s",s);
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]==' '||s[i]=='%')
		{
			t=0;
			for(j=k+1;j<i;j++)
				a[t++]=s[j];
			if(a[t-1]=='N'&&a[0]=='A')
				{
					for(j=t-1;j>=0;j--)
					{
						printf("%c",a[j]);	
					}
					
				}
			else{
				for(j=0;j<t;j++)
					printf("%c",a[j]);
				
		        }		
			k=i;
		    if(i!=n-1){printf(" ");}
		}	
	}	
	printf("%%\n");
	system("pause");
	return 0;
}
