#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int mm=10000+10;
char a1[mm],a2[mm];
int x1[mm],x2[mm];
int l1,l2,move=0;
int x[mm*2];
void set()
{
//	cout<<"*";
	int i;
	for(i=1;i<x1[0]+x2[0]+2;i++)
	{
		x[i+1]=x[i+1]+x[i]/10;
		x[i]=x[i]%10;
	}
}
int find()
{
	int i;
	for(i=mm*2-2;i>=0;i--)
		if(x[i]!=0)
		{
//			cout<<"***"<<x[i]<<"***";
			return i;
		}
}
/*
void print()
{
	int i;
	for(i=1;i<=x1[0]+x2[0]+2;i++)
		printf("%3d ",x[i]);
	cout<<endl;
}
*/
int main()
{
	FILE *fin,*fout;
	fin=freopen("x.in","r",stdin);
	fout=freopen("x.out","w",stdout);
	
	int i,j,point;
	scanf("%s",a1);
	scanf("%s",a2);
	l1=strlen(a1);l2=strlen(a2);
	x1[0]=l1;x2[0]=l2;
//	cout<<l1<<' '<<l2<<endl;
//	cout<<a1<<a2;
	point=0;
	for(i=l1-1;i>=0;i--)
	{
		x1[++point]=a1[i]-48;
//		cout<<x1[point]<<" ";
	}
	point=0;
//	cout<<endl;
	for(i=l2-1;i>=0;i--)
	{
		x2[++point]=a2[i]-48;
//		cout<<x2[point]<<" ";
	}
	
	if((x1[0]==1 && x1[1]==0) || (x2[0]==1 && x2[1]==0))
	{
		cout<<0;
	}
	else
	{
	
	for(i=1;i<=x1[0];i++)//main
	{
		for(j=1;j<=x2[0];j++)
		{
			x[j+move]+=x1[i]*x2[j];
		}
		move++;
//		print();
		set();
//		print();
	}
	set();
//	cout<<x1[0]<<endl<<x2[0]<<endl;
	int m=find();
//	cout<<m<<endl;
//	for(i=1;i<=m;i++)
//		cout<<x[i]<<' ';
//	cout<<endl;
	for(i=m;i>=1;i--)
		cout<<x[i];
		
	}
	cout<<endl;
	fclose(fin);fclose(fout);
	return 0;
}
