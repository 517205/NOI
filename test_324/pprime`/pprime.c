#include<stdio.h>
#include<math.h>
int judge(int x)
{
		int c=1,m=sqrt(x);
		int k;
		for(k=2;k<=m;k++)
				if(x%k==0) return 0;
		return 1;	
}

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

	for(i=1;i<=9;i=i+2)
		for(j=0;j<=9;j++){
			x=i*101+j*10;
			if(judge(x) &&( x>=a && x<=b) )
			        fprintf(fout,"%d\n",x);
		}

	for(i=1;i<=9;i=i+2)
		for(j=0;j<=9;j++)
			for(i1=0;i1<=9;i1++){
				x=i*10001+j*1010+i1*100;
			    if(judge(x) &&( x>=a && x<=b) )
			        fprintf(fout,"%d\n",x);
		    }

	for(i=1;i<=9;i=i+2)
		for(j=0;j<=9;j++)
			for(i1=0;i1<=9;i1++)
				for(j1=0;j1<=9;j1++){
					x=i*1000001+j*100010+i1*10100+j1*1000;
			   	    if(judge(x) &&( x>=a && x<=b) )
			           fprintf(fout,"%d\n",x);
				}
	fclose(fin);fclose(fout);
	return 0;
}		
