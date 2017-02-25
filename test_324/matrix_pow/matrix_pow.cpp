#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,k;
const int N=101;
const int M=(1<<31)-1;
struct matrix
{
    int a[N][N];
};
matrix aa,ans;
matrix mul(matrix x,matrix y)
{
    int i,j,k;
    matrix tt;
    memset(tt.a,0,sizeof(tt.a));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                tt.a[i][j]+=x.a[i][k]*y.a[k][j];
            }
    return tt;
}
void quickpow(int kk,matrix org)//org^kk
{
    int i;
    memset(ans.a,0,sizeof(ans.a));
    for(i=1;i<=n;i++)
        ans.a[i][i]=1;
    while(kk)
    {
        if(kk&1)
            ans=mul(ans,org);
        org=mul(org,org);
        kk=kk>>1;
    }
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("matrix_pow.in","r",stdin);
	fout=freopen("matrix_pow.out","w",stdout);
	
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	       cin>>aa.a[i][j];
	/*
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	       cout<<aa.a[i][j]<<" ";
		cout<<endl;
	}
	*/
	cin>>k;
	quickpow(k,aa);
	for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
            cout<<ans.a[i][j]<<' ';
        cout<<endl;
    }
	fclose(fin);fclose(fout);
	return 0;
}
