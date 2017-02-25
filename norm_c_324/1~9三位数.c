#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,a,b,c,x,t,a1[10]={0},b1[10]={0},c1[10]={0},j,m;
    int hash[10]={0};
    for(a=100;a<=334;a++)
    {
        b=a*2;
        c=a*3;
        x=a;t=0;
        while(x>0)
        {
            a1[++t]=x%10;
            x=x/10;
        }
        hash[a1[1]]++;
        hash[a1[2]]++;
        hash[a1[3]]++;
        x=b;t=0;
        while(x>0)
        {
            b1[++t]=x%10;
            x=x/10;
        }
        hash[b1[1]]++;
        hash[b1[2]]++;
        hash[b1[3]]++;
        x=c;t=0;
        while(x>0)
        {
            c1[++t]=x%10;
            x=x/10;
        }
        hash[c1[1]]++;
        hash[c1[2]]++;
        hash[c1[3]]++;
        m=1;
        for(i=1;i<=9;i++)
            if(hash[i]!=1) m=0;
        if(m==1) printf("%d %d %d\n",a,b,c);
        for(j=1;j<=9;j++)
            hash[j]=0;
    }
    printf("\n");
    system("pause");
    return 0;
}
