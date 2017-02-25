#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int N=10000+1;
const int M=100+1;//sqrt(N+0.5);
int  flag[N],prime[N],cnt=0;
int main()
{
    for(int i=2;i<=M;i++)
    {
        if(flag[i]) continue;
        for(int j=i*i;j<=N;j+=i)
            flag[j]=1;
    }
    for(int i=2;i<=N;i++)
        if(flag[i]==0) prime[++cnt]=i;
	for(int i=1;i<=cnt;i++)
	   printf("%5d",prime[i]);
	cout<<endl;
	system("pause"); 
	return 0;
}
