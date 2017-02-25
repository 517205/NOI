#include<stdio.h>
int i,j,n,m,z=1,t,k,a;
int hash1[50]={0},hash2[50]={0};
char s1[200],s2[200],s[200];
int main()
{
	FILE *fin,*fout;
	fin=fopen("spy.in","r");
	fout=fopen("spy.out","w");
	

	fscanf(fin,"%s",s1);
	fscanf(fin,"%s",s2);
	fscanf(fin,"%s",s);
	n=strlen(s1);
	m=strlen(s);
	
/*	for(i=0;i<n;i++)
	{
		hash1[s1[i]-64]++;
		hash2[s2[i]-64]++;
	}	*/
		
	for(i=0;i<n;i++)
	{
		k=s1[i]-64;
		if(hash1[k]==0||hash1[k]==s2[i])
			hash1[k]=s2[i];
		else 
		{
			fprintf(fout,"Failed");
			return 0;
		}
	}
	for(i=0;i<n;i++)
	{
		k=s2[i]-64;
		if(hash2[k]==0||hash2[k]==s1[i])
			hash2[k]=s1[i];
		else 
		{
			fprintf(fout,"Failed");
			return 0;
		}
	}	
		
		
	for(i=1;i<=26;i++)
	{
		if(hash1[i]==0)
			{
				fprintf(fout,"Failed");
				return 0;
			}
	}
	
/*	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(s[i]==s1[j]) 
			{
				fprintf(fout,"%c",s2[j]);
				break;
			}*/
	for(i=0;i<m;i++)
	{
		k=s[i]-64;
		fprintf(fout,"%c",hash1[k]);
	}
	fclose(fin);fclose(fout);
	return 0;
}
