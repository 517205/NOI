#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100001]={0};
int n,m;
int main()
{
	FILE *fin,*fout;
	fin=freopen("approach.in","r",stdin);
	fout=freopen("approach.out","w",stdout);
	
	cin>>n;
	int i;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	/*
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
		*/
	cin>>m;
	int t;
	for(i=1;i<=m;i++)
	{
		cin>>t;
		int l=1,r=n,mid;
		if(t>=a[r]) cout<<a[r]<<"\n";
		else if(t<=a[l]) cout<<a[l]<<"\n";
		else
		{
				
			while(l<r-1)
			{
				mid=(l+r)/2;
			//	cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<"\n";
				if(a[mid]<=t) l=mid;
				else if(a[mid]>t) r=mid;
			//	else if(a[mid]==t) break;
			}
			int aa1=abs(t-a[l]);
			int aa2=abs(a[mid]-t);
			int aa3=abs(a[r]-t);
			int xx,x;
			x=min(aa1,aa2);
			x=min(x,aa3);
			if(x==aa1) xx=a[l];
			else if(x==aa2) xx=a[mid];
			else if(x==aa3) xx=a[r];
			
			
			cout<<xx<<"\n";
			
		}
	}
	
	
	fclose(fin);fclose(fout);
	return 0;
}
