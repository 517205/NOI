#include<stdio.h>
int main()
{
    FILE *fin,*fout;
    fin=fopen("box.in","r");
    fout=fopen("box.out","w");

    int a,b,c;
    fscanf(fin,"%d%d",&a,&b);
    c=a+b;
    fprintf(fout,"%d\n",c);
    fclose(fin);fclose(fout);
    return 0;
}
