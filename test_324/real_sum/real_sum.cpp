#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char s1[200],s2[200];
int l1,l2,la1,la2,lb1,lb2,lc1,lc2;//1.2
int a1[200],a2[200],b1[200],b2[200],c1[200],c2[200];
int main()
{
	FILE *fin,*fout;
	fin=freopen("real_sum.in","r",stdin);
	fout=freopen("real_sum.out","w",stdout);
	
	scanf("%s",s1);
	scanf("%s",s2);
	l1=strlen(s1);l2=strlen(s2);
	int i,j;
	int c=0,point;
	for(i=0;i<l1;i++)
		if(s1[i]=='.')
		{
			la1=i;
			la2=l1-la1-1;
			break;
		}
	for(i=0;i<la1;i++)
		a1[la1-i]=s1[i]-48;
	point=0;
	for(i=la1+1;i<l1;i++)
		a2[++point]=s1[i]-48;
	for(i=0;i<l2;i++)
		if(s2[i]=='.')
		{
			lb1=i;
			lb2=l2-lb1-1;
			break;
		}
	for(i=0;i<lb1;i++)
		b1[lb1-i]=s2[i]-48;
	point=0;
	for(i=lb1+1;i<l2;i++)
		b2[++point]=s2[i]-48;
	
	/*
	for(i=1;i<=50;i++)
		cout<<a1[i];
	cout<<endl;
	for(i=1;i<=50;i++)
		cout<<a2[i];
	cout<<endl<<endl;
	
	for(i=1;i<=50;i++)
		cout<<b1[i];
	cout<<endl;
	for(i=1;i<=50;i++)
		cout<<b2[i];
	cout<<endl;
	*/
	
	for(i=199;i>=1;i--)
	{
		c2[i]+=(a2[i]+b2[i])%10;
		c2[i-1]+=(a2[i]+b2[i])/10;
		c2[i-1]+=c2[i]/10;
		c2[i]%=10;
	}
	
	/*
	for(i=0;i<=50;i++)
		cout<<c2[i];
	 cout<<endl<<endl;
	*/
	
	for(i=199;i>=1;i--)
		if(c2[i]!=0)
		{
			lc2=i;
			break;
		}
	c1[1]+=c2[0];
	
//	cout<<lc2<<endl;
	/*
	for(i=1;i<=50;i++)
		cout<<c2[i];
	cout<<endl<<endl;
	*/
	
	for(i=1;i<=198;i++)
	{
		c1[i]+=(a1[i]+b1[i])%10;
		c1[i+1]+=(a1[i]+b1[i])/10;
		c1[i+1]+=c1[i]/10;
		c1[i]%=10;
	}
	
	/*
	for(i=1;i<=50;i++)
		cout<<c1[i];
	cout<<endl;
	*/
	
	for(i=199;i>=0;i--)
		if(c1[i]!=0)
		{
			lc1=i;
			break;
		}
	for(i=lc1;i>=1;i--)
		cout<<c1[i];
	if(lc1==0) cout<<0;
	if(lc2!=0)
	{
		cout<<".";
		for(i=1;i<=lc2;i++)
			cout<<c2[i];
	}	
	cout<<endl;
	fclose(fin);fclose(fout);
	return 0;
}
