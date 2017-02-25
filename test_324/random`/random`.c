#include<stdio.h>
int hash[10000]={0};
int main()
{
	FILE *fin,*fout;
	fin=fopen("random`.in","r");
	fout=fopen("random`.out","w");
	
	int i,x=0,n,m;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d",&m);
		hash[m]++;
	}	
	for(i=1;i<=9999;i++)
		if(hash[i]>0) x++;
	fprintf(fout,"%d\n",x);
	for(i=1;i<=9999;i++)
		if(hash[i]!=0) 	fprintf(fout,"%d ",i);
	fclose(fin);fclose(fout);
	return 0;
}
