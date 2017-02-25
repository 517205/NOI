#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001]={0};
int main()
{
    FILE *fin,*fout;
    fin=freopen("norepeat.in","r",stdin);
    fout=freopen("norepeat.out","w",stdout);
    
    int n,i,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	printf("%d ",a[0]);
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
			printf("%d ",a[i]);
	}
    fclose(fin);fclose(fout);
    return 0;
}
