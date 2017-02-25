#include<iostream>
#include<cstdio>
using namespace std;

int a,b,n;
int d[110];
int cc;
int judge(int x)
{
	int i1=0,i2=0;
	while(x%2==0)
	{
		x=x/2;
		i1++;
	}
	while(x%5==0)
	{
		x=x/5;
		i2++;
	}
	if(i1>i2)
	cc=i1;
	else cc=i2;
	if(x==1) return 1;
	return 0;
	
}





int main()
{
	FILE *fin,*fout;
	fin=freopen("dot.in","r",stdin);
	fout=freopen("dot.out","w",stdout);
	
	scanf("%d%d%d",&a,&b,&n);
	int i,j,x,dd,tt,l=1,temp,c=1;//dd--ษฬ t--ำเ 

/*
e.g.
       0.07---->dd----->d[]
       _______________
a-> 13)1.0000000000000<-----b
         91
          9-------->tt
*/
	dd=a*10;
	for(i=1;i<=b;i++)
	{
		tt=dd%b;
		d[l++]=dd/b;
		dd=tt*10;
	}
/*
	for(i=0;i<=b+5;i++)
		printf("%d ",d[i]);
	printf("\n\n");
	*/
	/*
	if(d[1]!=d[b])
		c=0;
		*/
	if(judge(b)) c=0;
		
//	printf("\n\n\nc=%d\n\n\n",c);
		
	if(c==1)
	{
		if(b!=1)
			n=n%(b-1);
		if(n==0) n=b-1;
		printf("%d",d[n]);

	}
	if(c==0)
	{
		if(n>cc) printf("0");
		else printf("%d",d[n]);
	}
	
	
	
	
	
	
	fclose(fin);fclose(fout);
	return 0;
}
