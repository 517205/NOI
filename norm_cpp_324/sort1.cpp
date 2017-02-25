#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100]={0,5,6,9,8,5,4,1,5,3,4,2,9,6,4,1,7,8,9,5,2};
int n=20;
int main()
{
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	sort(a+1,a+21);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	sort(a+1,a+21,greater<int>());
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	system("pause");
	return 0;
}
