#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200000]={0};
int n,m;//n=day,m=month
int judge(int x)
{
	int i;
	int tt=1;
	int sum=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			return 0;
		}
		else if(a[i]+sum>x)
		{
			sum=a[i];
			tt++;
		}
		else sum+=a[i];
		if(tt>m) return 0;
	}
	if(tt>m) return 0;
	else return 1;
}
int main()
{
    FILE *fin,*fout;
    fin=freopen("month.in","r",stdin);
    fout=freopen("month.out","w",stdout);
    
    int l=0,r=20000,mid,i;
//	scanf("%d%d",&n,&m);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
//	i=1;
//	int flag=1;
	while(l<r-1)
	{
		mid=(l+r)/2;
//		printf("#%d:l=%d r=%d mid=%d\n",i++,l,r,mid);
		if(judge(mid)) r=mid;
		else l=mid;
	}
//	printf("\n#Last:l=%d r=%d mid=%d\n",l,r,mid);
	if(judge(l)) cout<<l<<"\n";
	else if(judge(mid)) cout<<mid<<"\n";
	else cout<<r<<"\n";
    fclose(fin);fclose(fout);
    return 0;
}
