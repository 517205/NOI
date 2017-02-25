#include<stdio.h>
int a[200000]={0},b[200000]={210000000};
int hash[500000]={0};
int main()
{
    FILE *fin,*fout;
    fin=fopen("fruit.in","r");
    fout=fopen("fruit.out","w");

    int i,j,x,n=0,sum=0,t=1,a1=0,a2=0,k=0,mm=0,xx,y,z,min;
    fscanf(fin,"%d",&x);
    for(i=1;i<=x;i++)
    {
        fscanf(fin,"%d",&a[i]);
        hash[a[i]]++;
    }
    for(i=1;i<=20000;i++)
    {
        for(j=1;j<=hash[i];j++)
            a[t++]=i;
        b[i]=210000000;
    }
    t=1;
    a[x+1]=210000000;a[x+2]=210000000;
    ///////////////////////
    a1=1; a2=1;
    for(i=1,j=1;i<x;i++)
    {
        min=210000000;
        xx=a[a1]+a[a1+1];
        y=a[a1]+b[a2];
        z=b[a2]+b[a2+1];
        if(xx<min) {mm=1;min=xx;}
        if(y<min) {mm=2;min=y;}
        if(z<min) {mm=3;min=z;}
        
        if(mm==1) {n=xx;a1=a1+2;}
        if(mm==2) {n=y;a1++;a2++;}
        if(mm==3) {n=z;a2=a2+2;}
        sum=sum+n;
        b[t++]=n;
    }
    fprintf(fout,"%d",sum);
    fclose(fin);fclose(fout);
    return 0;
}















