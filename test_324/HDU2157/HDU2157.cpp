#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=25;
const int M=(1<<31)-1;
const int MOD=1000;
int m=-1,n=-1;
struct matrix
{
    int a[N][N];
};
matrix map,tmp;
matrix mul(matrix x,matrix y,int nn)
{
    int i,j,k;
    matrix tt;
    memset(tt.a,0,sizeof(tt.a));
    for(i=1;i<=nn;i++)
        for(j=1;j<=nn;j++)
            for(k=1;k<=nn;k++)
            {
                tt.a[i][j]+=(x.a[i][k]*y.a[k][j])%MOD;
                tt.a[i][j]%=MOD;
            }
    return tt;
}
matrix quickpow(int kk,matrix org,int nn)//org^kk
{
    int i;
    matrix ans;
    memset(ans.a,0,sizeof(ans.a));
    for(i=1;i<=nn;i++)
        ans.a[i][i]=1;
    
    int j;
    /*
    cout<<"<ans.a>"<<endl;
    for(i=1;i<=nn;i++)
    {
		for(j=1;j<=nn;j++)
			cout<<ans.a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"<org.a>"<<endl;
	for(i=1;i<=nn;i++)
	{
		for(j=1;j<=nn;j++)
			cout<<org.a[i][j]<<" ";
		cout<<endl;
	}
	*/
    while(kk)
    {
        if(kk&1)
            ans=mul(ans,org,nn);
        org=mul(org,org,nn);
        /*
	    cout<<"<org.a>"<<endl;
	    for(i=1;i<=nn;i++)
		{
			for(j=1;j<=nn;j++)
				cout<<org.a[i][j]<<" ";
			cout<<endl;
		}
	    cout<<"<ans.a>"<<endl;
	    for(i=1;i<=nn;i++)
		{
			for(j=1;j<=nn;j++)
				cout<<ans.a[i][j]<<" ";
			cout<<endl;
		}
		*/
        kk=kk>>1;
    }
    return ans;
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("HDU2157.in","r",stdin);
	fout=freopen("HDU2157.out","w",stdout);
	
	
	int i,j,t1,t2,t,a,b,k;
	cin>>n>>m;
	do
	{
		for(i=1;i<=m;i++)
		{
			cin>>t1>>t2;
			map.a[t1+1][t2+1]=1;
		}
		/*
		cout<<"//////"<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				cout<<map.a[i][j]<<" ";
			cout<<endl;
		}
		cout<<"//////"<<endl;
		*/
		cin>>t;
		for(i=1;i<=t;i++)
		{
			cin>>a>>b>>k;
			tmp=quickpow(k,map,n);
			/*
			cout<<"///"<<endl;
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
					cout<<tmp.a[j][k]<<" ";
				cout<<endl;
			}
			cout<<"///"<<endl;
			*/
			cout<<tmp.a[a+1][b+1]<<endl;
		}
//		cout<<endl;
		cin>>n>>m;
	}while(n!=0 && m!=0);
	fclose(fin);fclose(fout);
	return 0;
}
