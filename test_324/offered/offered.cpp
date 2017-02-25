#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;//n=number m=offered
int a[100010];
int find(int x)
{
	int l=1,r=n,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(a[mid]<x) l=mid;
		else r=mid;
	}
	if(a[l]==x || a[mid]==x || a[r]==x)	return 1;
	else return 0;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("offered.in","r",stdin);
	fout=freopen("offered.out","w",stdout);
	
	int j,i,t,tfind;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	sort(a+1,a+n+1);
	/*
	for(i=1;i<=n;i++)
		cout<<a[i]<<" "; 
	cout<<endl;
	*/
	/*
	for(i=0;i<=10;i++)
	{
		cout<<find(i)<<endl;
	}
	cout<<endl;
	*/
	
	
	
	
	
	
	
	
	if(m>2*(10e8))
	{
		printf("No\n");
		fclose(fin);fclose(fout);
		return 0;		
	}
	else
	{
		for(i=1;i<=n && a[i]<=tfind+1;i++)
		{
			t=a[i];
			tfind=m-a[i];
			if(find(tfind))
			{
				int k=1;
				if(t==tfind)
				{
					if(a[i]==a[i-1] || a[i]==a[i+1])
						k=1;
					else k=0;
					
				//	cout<<"!"<<endl;
				}
				if(k==1)
				{
					cout<<t<<" "<<tfind<<endl;
					fclose(fin);fclose(fout);
					return 0;
				}
			}
		}		
	}
/*	
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
*/	
/*	
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
*/	
	cout<<"No"<<endl;
	fclose(fin);fclose(fout);
	return 0;
}
/*
	int t=n;
	for(i=1;i<t;i++)
	{
		if(a[i]>t)
		{
			printf("No\n");
			fclose(fin);fclose(fout);
			return 0;
		}
		else
		{
			for(j=i;j<=t;j++)
			{
				if(a[i]+a[j]>m) {break;t=j;}
				else
				if(a[i]+a[j]==m)
				{
					printf("%d %d\n",a[i],a[j]);
					fclose(fin);fclose(fout);
					return 0;
				}	
			}
		}
	}
	
	
	
	printf("No\n");	
	//50/100
	*/
