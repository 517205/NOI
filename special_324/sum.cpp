#include<iostream>
#include<cstdio>
using namespace std;

int a[300],b[300],ss[300];
char aa[300],bb[300];
int main()
{
	
	int i=0,suma=300,sumb=300,zeroa=0,zerob=0,big,enda=299,endb=299,end;
	for(i=0;i<=299;i++)
	{
		aa[i]='a';
		bb[i]='a';
		a[i]=100;
		b[i]=100;
	}
	scanf("%s",&aa);
	scanf("%s",&bb);
	i=0;
	while(aa[i]=='0')
	{
		zeroa++;
		i++;
	}
	i=0;
	while(bb[i]=='0')
	{
		zerob++;
		i++;
	}
	while(aa[enda]=='a')
	{
		suma--;
		enda--;
	}
	suma=suma-zeroa-1;
	while(bb[endb]=='a')
	{
		sumb--;
		endb--;
	}
	sumb=sumb-zerob-1;
	if(suma>=sumb) big=0;
	else big=1;
	if(big==0)
	{
		end=enda;
		for(i=zeroa+1;i<=enda;i++)
			a[i]=aa[i-1]-48;
		for(i=endb;i>=zerob+1;i--)
			b[i+(-endb+enda)]=bb[i-1]-48;
	}
	else
	{
		end=endb;
		for(i=zerob+1;i<=endb;i++)
			b[i]=bb[i-1]-48;
		for(i=enda;i>=zeroa+1;i--)
			a[i+(-enda+endb)]=aa[i-1]-48;
	}
	i=0;
	while(a[i]==100)
	{
		a[i]=0;
		i++;
	}
	i=0;
	while(b[i]==100)
	{
		b[i]=0;
		i++;
	}
	for(i=end;i>=1;i--)
	{
		ss[i]=ss[i]+a[i]+b[i];
		if(ss[i]>=10)
		{
			ss[i]-=10;
			ss[i-1]++;
		}		
	}
	i=0;
	while(ss[i]==0) i++;
	int xx=i;
	for(i=xx;i<=end;i++)
		printf("%d",ss[i]);
	cout<<endl;
	if(xx>end) printf("0\n");
	system("pause");

	return 0;
}
