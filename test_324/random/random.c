#include<stdio.h>
int a[200]={0},a1[200]={0};
int main()
{
	FILE *fin,*fout;
	fin=fopen("random.in","r");
	fout=fopen("random.out","w");
	
	int n,i,j,x,t,x1=0;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d",&a[i]);
		a1[i]=a[i];
	}
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
		{
			if(a1[i]>a1[j])
			{
				t=a1[i];
				a1[i]=a1[j];
				a1[j]=t;
			}
		}
	for(i=2;i<=n;i++)
	{
		if(a1[i]==a1[i-1]) 
		{
			x1=x1+1;
		}
	}
	x=n-x1;
	fprintf(fout,"%d\n",x);
	for(i=1;i<=n-1;i++)
	{
		if(a1[i]!=a1[i+1]) fprintf(fout,"%d ",a1[i]);
	}
	fprintf(fout,"%d",a1[n]);
	fclose(fin);fclose(fout);
	return 0;
}
	//fprintf(fout,"111111111\n");
	//fprintf(fout,"111111111\n");
	//fprintf(fout,"111111111\n");	
