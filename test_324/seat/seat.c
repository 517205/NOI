#include<stdio.h>
int x[10000]={0},y[10000]={0},p[10000]={0},q[10000]={0};
struct a
{
	int key;
	int num;
}stu[10000],temp;
struct a1
{
	int key1;
	int num1;
}stu1[10000],temp1;
int main()
{
	FILE *fin,*fout;
	fin=fopen("seat.in","r");
	fout=fopen("seat.out","w");
	
	int M,N,K,L,D;
	int i,j,k;
	fscanf(fin,"%d%d%d%d%d",&M,&N,&K,&L,&D);
	for(i=1;i<=D;i++)
	{
		fscanf(fin,"%d%d%d%d",&x[i],&y[i],&p[i],&q[i]);
		if(x[i]==p[i]&&y[i]<=q[i]) stu[y[i]].num++;
		if(x[i]==p[i]&&y[i]>q[i]) stu[q[i]].num++;
		if(y[i]==q[i]&&x[i]<=p[i]) stu1[x[i]].num1++;
		if(y[i]==q[i]&&x[i]>p[i]) stu1[p[i]].num1++;
	}
	int c=0;
	for(i=1;i<10000;i++)
	{
		if (stu[i].num!=0)
		{
		 	stu[i].key=i;
		 	stu[++c].num=stu[i].num;
		 	stu[c].key=stu[i].key;
	    }
	}
	int c1=0;
	for(i=1;i<10000;i++)
	{
		if (stu1[i].num1!=0)
		{
		 	stu1[i].key1=i;
		 	stu1[++c1].num1=stu1[i].num1;
		 	stu1[c1].key1=stu1[i].key1;
	    }
	}
	for(i=1;i<c;i++)
		for(j=i+1;j<=c;j++)
		{
			if(stu[i].num<stu[j].num)
			{
				temp=stu[j];
				stu[j]=stu[i];
				stu[i]=temp;
			}
		}
	for(i=1;i<c1;i++)
		for(j=i+1;j<=c1;j++)
		{
			if(stu1[i].num1<stu1[j].num1)
			{
				temp1=stu1[j];
				stu1[j]=stu1[i];
				stu1[i]=temp1;
			}
		}
    for(i=1;i<L;i++)
		for(j=i+1;j<=L;j++)
		{
			if(stu[i].key>stu[j].key)
			{
				temp=stu[j];
				stu[j]=stu[i];
				stu[i]=temp;
			}
		}		
	for(i=1;i<K;i++)
		for(j=i+1;j<=K;j++)
		{
			if(stu1[i].key1>stu1[j].key1)
			{
				temp1=stu1[j];
				stu1[j]=stu1[i];
				stu1[i]=temp1;
			}
		}		
	for(i=1;i<=K;i++)
	{
		fprintf(fout,"%d",stu1[i].key1);
		if(i==K) fprintf(fout,"\n");
		else fprintf(fout," ");
	}
	for(i=1;i<=L;i++)
	{
		fprintf(fout,"%d",stu[i].key);
		if(i==L) fprintf(fout,"");
		else fprintf(fout," ");
	}
	fclose(fin);fclose(fout);
	return 0;
}
