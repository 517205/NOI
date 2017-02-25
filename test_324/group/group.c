#include<stdio.h>
int p[100000]={0};//price   formal
int a1[100000]={0};//temporary
int hash[300]={0};//price  [5,200]
int hash1[100000]={0};
int main()
{
    FILE *fin,*fout;
    fin=fopen("data_2.txt","r");
    fout=fopen("group.out","w");

    int w,n,i,j,t=1,sum=0,a,b,x;
    fscanf(fin,"%d",&w);//80<=W<=200(upline)
    fscanf(fin,"%d",&n);//1<=n<=30000(sum)
    if(n==1) fprintf(fout,"(0)1");
    else
    {
    
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&a1[i]);
        hash[a1[i]]++;
    }
    for(i=1;i<=200;i++)
    {
        for(j=1;j<=hash[i];j++)
        {
            p[t++]=i;
        }
    }
    //OK
    a=1;b=n;
    for(i=1;i>=1,a<b;i++)
    {
        if(p[a]+p[b]<=w)
        {
            x=p[a]+p[b];
            a=a+1;b=b-1;
            hash1[a]=1;hash1[b]=1;
            while(x+p[b]<=w&&a!=b)
            {
                x=x+p[b];
                b=b-1;
                hash1[b]=1;
            }
            while(x+p[a]<=w&&a!=b)
            {
                x=x+p[a];
                a=a+1;
                hash1[a]=1;
            }
            sum++;
        }
        else
        {
            b=b-1;
            sum++;
            hash1[b]=1;
        }
    }
    fprintf(fout,"%d %d %d\n",a,b,sum);
    if(a==b)
    {
        if(x+p[a]<=w && hash1[a]==0)
            fprintf(fout,"\n(1)%d\n",sum);
        if(x+p[a]>w && hash1[a]==0)
            fprintf(fout,"\n(2)%d\n",sum+1);
        if(x+p[a]<=w && hash1[a]==1)
            fprintf(fout,"\n(3)%d\n",sum);
        if(x+p[a]>w && hash1[a]==1)
            fprintf(fout,"\n(4)%d\n",sum+1);

    }
    else
        fprintf(fout,"\n(5)%d\n",sum);
        
    }
    fclose(fin);fclose(fout);
    return 0;
}
/*
    for(i=1;i<=99999,p[i]!=0;i++)
    {
        fprintf(fout,"%d\n",p[i]);
    }
*/
/*    if(a==b && x+p[a]>w)
        fprintf(fout,"\n(1)%d\n",sum+1);
    else if(a==b && x+p[a]<=w && x!=0)
        fprintf(fout,"\n(2)%d\n",sum);
    else if(a==b && x==0)
        fprintf(fout,"\n(3)%d\n",sum+1);
        
*/
/*        if(hash1[a]==0)
            fprintf(fout,"\n(2)%d\n",sum);
*/






