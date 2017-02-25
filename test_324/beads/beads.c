#include<stdio.h>
int a[1000]={0};
char s[1000];
int main()
{
	FILE *fin,*fout;
	fin=fopen("beads.in","r");
	fout=fopen("beads.out","w");
	
	int i,n,l,r,lget,rget,sign,sum,ans=0;
	fscanf(fin,"%d\n",&n);
	for(i=0;i<=n-1;i++)
	{
		fscanf(fin,"%c",&s[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		if(s[i]=='r') a[i]=2;
		if(s[i]=='b') a[i]=6;
		if(s[i]=='w') a[i]=9;
	}
	for(i=0;i<=n-1;i++)
	{
		if(s[i]=='r') a[i+n]=2;
		if(s[i]=='b') a[i+n]=6;
		if(s[i]=='w') a[i+n]=9;
	}	
	//////////////////////////////////
	for(i=0;i<=n;i++)
	{
		l=i;r=i+n-1;lget=0;rget=0;
		while(l<=r&&a[l]==9)
		{
			l++;
			lget++;
		}
		sign=a[l];
		while(l<=r&&(a[l]==9||a[l]==sign))
		{
			l++;
			lget++;
		}
		//////////////////////////////////
		while(l<=r&&a[r]==9)
		{
			r--;
			rget++;
		}
		sign=a[r];
		while(l<=r&&(a[r]==9||a[r]==sign))
		{
			r--;
			rget++;
		}
		sum=lget+rget;
		if(sum>n) sum=n;
		if(sum>ans) ans=sum;
	}
	////////////////////////////////////
	fprintf(fout,"%d",ans);
	fclose(fin);fclose(fout);
	return 0;
}
