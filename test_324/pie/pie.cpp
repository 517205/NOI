#include<iostream>
#include<cstdio>
using namespace std;

const double pi=3.14159265358979;
const int maxn=10000+10;
int n,f;//n=number of pie,f=munber of friend
double a[maxn]={0};

int judge(double x)
{
	int sum=0,i,j;
	for(i=1;i<=n;i++)
	{
		double t=a[i];
		while(t>x)
		{
			sum++;
			t-=x;
		}
		if(sum>=f) return 1;
	}
	return 0;
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("pie.in","r",stdin);
	fout=freopen("pie.out","w",stdout);
	
	cin>>n>>f;
	f+=1;
	int i;
	double t;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=pi*t*t;
	}
	double l=0.0,r=4e8,mid;
	while(r-l>1e-6)
	{
		mid=(l+r)/2;
	//	printf("l=%f r=%f mid=%f\n",l,r,mid);
		if(judge(mid)) l=mid;
		else r=mid;
		
	}
	printf("%.3f\n",l);
	fclose(fin);fclose(fout);
	return 0;
}
