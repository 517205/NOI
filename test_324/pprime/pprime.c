#include<stdio.h>
#include<math.h>
int main()
{
	FILE *fin,*fout;
	fin=fopen("pprime.in","r");
	fout=fopen("pprime.out","w");
	
	int a,b,i,j,i1,j1,c=1,m,k,x=0;
	fscanf(fin,"%d%d",&a,&b);
	if(a<=5&&5<=b) fprintf(fout,"5\n");
	if(a<=7&&7<=b) fprintf(fout,"7\n");		
	if(a<=11&&11<=b) fprintf(fout,"11\n");	
	//////////////////////////////////////
	if(b>100&&a<1000)
	{
	for(i=1;i<=9;i=i+2)
		for(j=0;j<=9;j++)
		{
			x=i*101+j*10;
			if(x>=a&&x<=b)
			{
			c=1;m=sqrt(x);
			for(k=2;k<=m+1;k++)
			{
				if(x%k==0) c=0;
			}
			if(c==1) fprintf(fout,"%d\n",x);
			}
			x=0;
		}
	}
	if(b>10000&&a<100000)
	{
	for(i=1;i<=9;i=i+2)
		for(j=0;j<=9;j++)
			for(i1=0;i1<=9;i1++)
			{
				x=i*10001+j*1010+i1*100;
				if(x>=a&&x<=b)
				{
				c=1;m=sqrt(x);
				for(k=2;k<=m+1;k++)
				{
					if(x%k==0) c=0;
				}
				if(c==1) fprintf(fout,"%d\n",x);
				}
				x=0;
			}
	}
	if(b>1000000&&a<10000000)
	{
	for(i=1;i<=9;i=i+2)
		for(j=0;j<=9;j++)
			for(i1=0;i1<=9;i1++)
				for(j1=0;j1<=9;j1++)
				{
					x=i*1000001+j*100010+i1*10100+j1*1000;
					if(x>=a&&x<=b)
					{
					c=1;m=sqrt(x);
					for(k=2;k<=m+1;k++)
					{
						if(x%k==0) c=0;
					}
					if(c==1) fprintf(fout,"%d\n",x);
					x=0;
					}
				}
	}
	fclose(fin);fclose(fout);
	return 0;
}		
