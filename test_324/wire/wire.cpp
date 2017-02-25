#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,k;
double m[20000]={0};//meter
int judge(double x)
{
	int i,sum=0;
	for(i=1;i<=n;i++)
	{
		double t=m[i];
		while(t>=x)
		{
			t-=x;
			sum++;
		}
		if(sum>=k) return 1;
	}
	return 0;
}
int main()
{
    FILE *fin,*fout;
    fin=freopen("wire.in","r",stdin);
    fout=freopen("wire.out","w",stdout);
	
	int i,kk=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lf",&m[i]);
	double l=0.0,r=100001.0,mid=(l+r)/2;
	while(r-l>0.009)
	{
//		kk++;
		mid=(l+r)/2;
//		printf("l=%f r=%f mid=%f\n",l,r,mid);
		if(judge(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
//		if(kk>50)
		if(r<0.01)
		{
			printf("0.00\n");
			fclose(fin);fclose(fout);
			return 0;
		}
	}
	if(judge(r))
		printf("%.2f\n",r);
	else if(judge(mid))
		printf("%.2f\n",mid);
	else if(judge(l))
		printf("%.2f\n",l);
    fclose(fin);fclose(fout);
    return 0;
}
