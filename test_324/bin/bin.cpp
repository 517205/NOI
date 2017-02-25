#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int bin[33]={0};
long long x;
int ff;
int ABS(long long aa)
{
	if(aa>0) return aa;
	return -aa;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("bin.in","r",stdin);
	fout=freopen("bin.out","w",stdout);
	
	cin>>x;
	if(x>=0) ff=0;
	else
	{
		ff=1;
		x=ABS(x);
	}
	bin[1]=ff;
//	cout<<ff;
	int i;
	for(i=32;i>=1;i--)
	{
		bin[i]+=x%2;
		x/=2;
	}
	if(ff==1)
	{
	
		for(i=32;i>=2;i--)
		{
			if(bin[i]==1) bin[i]=0;
			else bin[i]=1;
		}
		bin[32]++;
	}
	for(i=32;i>=2;i--)
	{
		if(bin[i]==2)
		{
			bin[i]=0;
			bin[i-1]++;
		}
	}
	
	
	
	for(i=1;i<=32;i++)
		cout<<bin[i];
	cout<<endl;
	fclose(fin);fclose(fout);
	return 0;
}
