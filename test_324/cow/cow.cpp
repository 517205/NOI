#include<iostream>
#include<cstdio>
using namespace std;

int a[50005]={0};//location of rock
int L,n,m;//m=move away,n=number of rock
int l,r,mid;
int judge(int x)//0--fail,1--ok
{
	int i=0,j;
	int used=0;
	while(used<=m)
	{
		if(i>=n) return 1;
		if(a[i+1]-a[i]>=x)
			i++;
		else
		{
			j=i+1;
			while(a[j]-a[i]<x)
			{
//				if(used<=m)
					used++;
//				else return 0;
				j++;
			}
			i=j;
			j=0;
		}
	}
	return 0;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("cow.in","r",stdin);
	fout=freopen("cow.out","w",stdout);
	
	int j,i;
	scanf("%d%d%d",&L,&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	a[n+1]=L;a[0]=0;
	l=0;r=L+1;
	//////////////
//	int tt=judge(3);
	//////////////
	while(l<r-1)//(0,left]--ok   (left,right)--maybe     [right,L]--fail
	{
		mid=(l+r)/2;
		if(judge(mid))
		{
			l=mid;
	//		printf("mid=%d judge!\n",mid);
		}
		else
		{
			r=mid;
	//		printf("mid=%d not judge!\n",mid);
		}
	}
	printf("%d\n",l);
	fclose(fin);fclose(fout);
	return 0;
}
