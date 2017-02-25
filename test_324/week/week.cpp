#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a,b,ans;
char aa[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int pow(int x,int y)
{
	if(x==0) return 1;
	int org=x,res=1,k=y;
	while(k)
	{
		if(k&1) res=(res*org)%7;
		org=(org*org)%7;
		k>>=1;
	}
	return res;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("week.in","r",stdin);
	fout=freopen("week.out","w",stdout);
	
	cin>>a>>b;
	ans=pow(a,b);
	printf("%s\n",aa[ans]);
	fclose(fin);fclose(fout);
	return 0;
}
