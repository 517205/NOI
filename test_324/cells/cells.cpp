#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int map[10][10]={0};
int newmap[10][10]={0};
void nnew()
{
    int i,j,t;
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
        {
            t=map[i][j];
            newmap[i][j]+=2*t;
            newmap[i+1][j+1]+=t;
            newmap[i+1][j]+=t;
            newmap[i][j+1]+=t;
            newmap[i-1][j-1]+=t;
            newmap[i-1][j]+=t;
            newmap[i][j-1]+=t;
            newmap[i+1][j-1]+=t;
            newmap[i-1][j+1]+=t;
        }
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
            map[i][j]=newmap[i][j];
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
            newmap[i][j]=0;
    
}
int main()
{
    FILE *fin,*fout;
    fin=freopen("cells.in","r",stdin);
    fout=freopen("cells.out","w",stdout);
    
    int m,n;//m=number,n=day
    int i,j;
    scanf("%d%d",&m,&n);
    map[5][5]=m;
    for(i=1;i<=n;i++)
        nnew();
    
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
    
    
    fclose(fin);fclose(fout);
    return 0;
}
