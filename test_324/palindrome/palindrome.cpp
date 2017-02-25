#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char a[600];
int judge(int x,int y)
{
	int i;
	for(i=0;(x+i)<=(y-i);i++)
	{
		int k1=x+i;
		int k2=y-i;
		if(a[k1]!=a[k2]) return 0;
	}
	return 1;	
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("palindrome.in","r",stdin);
	fout=freopen("palindrome.out","w",stdout);
	
	scanf("%s",a);
	int l=strlen(a);
	int i,j,k;
	for(i=1;i<l;i++)
	{	
		for(j=0;j<l-i;j++)
		{
			if(judge(j,j+i))
			{
				for(k=j;k<=j+i;k++)
					cout<<a[k];
				cout<<endl;
			}
		}
	} 
	
	
	fclose(fin);fclose(fout);
	return 0;
}
