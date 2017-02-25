#include<stdio.h>
int a0[10000]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    FILE *fin,*fout;
    fin=fopen("matches.in","r");
    fout=fopen("matches.out","w");
    int i,j,x,m=0,x1,a=0,b=0,c=0,n,t1,t2,t3;
    fscanf(fin,"%d",&x1);
    x=x1-4;
    for(i=10;i<=9999;i++)
        a0[i]=a0[i%10]+a0[i/10];
    for(i=0;i<=999;i++)
        for(j=0;j<=999;j++)
        {
            t3=i+j;
            t1=i;t2=j;
            a=a0[t1];b=a0[t2];c=a0[t3];
            n=a+b+c;
            if(n==x) m=m+1;
        }
    fprintf(fout,"%d\n",m);
    fclose(fin);fclose(fout);
    return 0;
}
