#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,i,n,a,j;
	char s[50],t;
	gets(s);
	n=strlen(s);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{

			if((s[i]>=65&&s[i]<=90)&&(s[j]>=65&&s[j]<=90)&&s[i]>s[j])
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
				a=0;
			}
		}

	for(i=0;i<n;i++)
	{
		printf("%c",s[i]);
		if(s[i]==0){printf(" ");}
	}
	printf("\n");
	system("pause");
	return 0;
}
