#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef struct point
{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
};
struct cmp
{
	bool operator()(const point &a,const point &b)
	{
		if(a.x==b.x) return a.y>b.y;
		return a.x>b.x;
	}
};
int main()
{
	point a[10]={point(0,0),point(1,5),point(1,4),point(1,7),point(0,3),point(5,6),point(-4,1)};
	priority_queue<point,vector<point>,cmp>qq;
	printf("[point(0,0),]point(1,5),point(1,4),point(1,7),point(0,3),point(5,6),point(-4,1)\n");
	printf("priority_queue<point,vector<point>,cmp>qq;   :\n\n");
	for(int i=1;i<=6;i++)
	{
		qq.push(a[i]);
		point k=qq.top();
		printf("%d %d\n",k.x,k.y);
	}
	system("pause");
	return 0;
}
