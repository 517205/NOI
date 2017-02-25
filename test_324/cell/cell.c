#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define X 30001
int a[X]={0};
int a1[X]={0};
int t;
int s1[X]={0};
int s[X]={0};
int main()
{
	FILE *fin,*fout;
	fin=fopen("cell.in","r");
	fout=fopen("cell.out","w");
	
	t1(X);
	int x,k,i,m1,m2,j,temp,time0=0,time=0,tans=2100000000;
	fscanf(fin,"%d",&x);
	fscanf(fin,"%d%d",&m1,&m2);
	if(m1==1)
        {fprintf(fout,"0\n");  fclose(fin);fclose(fout);return 0;}
    int stop=t3(m1);
	for(i=1;i<=m1;i++)
		s1[i]=s1[i]*m2;
		
	for(i=1;i<=x;i++)
	{
		memset(s,0,sizeof(s));
		fscanf(fin,"%d",&temp);
		if(temp!=1)
		{
		  t2(temp);
		for(j=1;j<=stop;j++)
		{
		     if (s[j]!=0 && s1[j]%s[j]==0)
				time = s1[j]/s[j];
			 if (s[j]!=0 && s1[j]%s[j]!=0)
				time = s1[j]/s[j]+1;
			 if (s[j]==0 && s1[j]!=0)
			    {
					time0=0;
					break;
				}
			 if (time>time0) time0=time;
		}
		if(time0!=0)
			{
			if(tans>time0) tans=time0;
			}
		time0=0;
		}
	}
	if(tans!=2100000000)
		fprintf(fout,"%d\n",tans);
    else fprintf(fout,"-1\n");
    fprintf(fout,"\nTime used:%0.2f\n",(double)clock()/CLOCKS_PER_SEC);
	fclose(fin);fclose(fout);
	return 0;
}
int t1(int z)
{
	int i,j,k;
    for(i=2;i<=z;i++)a[i]=1;
    for(i=2;i<=sqrt(z);i++){
		if (a[i])
		  for(k=i+i;k<=z;k=k+i)
         	  a[k]=0;
    }
    for(i=2;i<=z;i++)
        if(a[i]!=0)a1[++t]=i;
}


int t2(int x)
{
	int x1=x,i;
	for(i=1;x1!=1&&i<=t;i++){
		while(x1%a1[i]==0 && x1!=1 )
		{
			x1=x1/a1[i];
			s[i]++;
		}
	}
}
int t3(int x)
{
	int x1=x,i;
	for(i=1;x1!=1&&i<=t;i++)
	{
		while(x1% a1[i]==0 && x1!=1){
			x1=x1/a1[i];
			s1[i]++;
		}
	}
	return i-1;
}


//    fprintf(fout,"c=%d l=%d ll=%d",c,l,ll);
//		fprintf(fout,"\n");
			//fprintf(fout,"%d ",time0);
			//fprintf(fout,"time=%d time0=%d   ",time,time0);
			//		for(j=1;j<=10;j++)
//			fprintf(fout,"%d ",s[j]);
//		fprintf(fout,"\n");
//fprintf(fout,"l=%d ll=%d\n",l,ll);


//	for(i=1;i<=m1;i++)
//	    fprintf(fout,"%d ",s1[i]);
//	fprintf(fout,"\n\n");
//			fprintf(fout,"\nTime used:%0.2f\n",(double)clock()/CLOCKS_PER_SEC);
//main start//main end
//					system("pause");
