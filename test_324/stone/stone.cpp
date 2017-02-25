#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long a=-1,b=-1;//a>=b
int first;//==1,==0
int main()
{
	FILE *fin,*fout;
	fin=freopen("stone.in","r",stdin);
	fout=freopen("stone.out","w",stdout);
	
	cin>>a>>b;
	if(a && b)
	do
	{
		first=1;
		while(a!=0 && b!=0)
		{
			if(a<b) swap(a,b);
			if(a==b) break;
			if(a>=b*2) break;
			else a-=b;
			first=!first;
		}
		if(first==1) cout<<"win"<<endl;
		else cout<<"lose"<<endl;
		cin>>a>>b;
	}while(a!=0 && b!=0);
	fclose(fin);fclose(fout);
	return 0;
}

