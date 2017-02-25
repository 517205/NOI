#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100]={0,5,6,9,8,5,4,1,5,3,4,2,9,7,4,1,7,8,9,5,2};
int b[100]={0,6,5,6,9,8,7,4,1,2,5,8,4,6,9,1,2,5,8,9,6};
int n=20;

struct point
{
	int x,y;
	bool operator<(const point& other)const
	{
		return x<other.x || (x==other.x && y>other.y);
	}
};
point xx[200];

int main()
{

	for(int i=1;i<=n;i++)
	{
		xx[i].x=a[i];
		xx[i].y=b[i];
	}
	
	printf("xx[]:");
	for(int i=1;i<=n;i++)
		printf("%d ",xx[i]);
	printf("\n\n");
	
	sort(xx+1,xx+21);
	
	printf("xx[]:");
	for(int i=1;i<=n;i++)
		printf("%d ",xx[i]);
	printf("\n\n");
	system("pause");
	return 0;
}
