#include<stdio.h>
int main()
{
    FILE *fin,*fout;
    fin=fopen("apple.in","r");
    fout=fopen("apple.out","w");
    
    int a[11]={0};
    int x,i,m=0;
    for(i=1;i<=10;i++)
    {
        fscanf(fin,"%d",&a[i]);
    }
    fscanf(fin,"%d",&x);
    for(i=1;i<=10;i++)
    {
        if(a[i]<=x+30) m=m+1;
    }
    fprintf(fout,"%d\n",m);
    fclose(fin);fclose(fout);
    return 0;
}

    
