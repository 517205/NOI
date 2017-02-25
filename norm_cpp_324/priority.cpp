#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int main()
{
	priority_queue<int>qq;
	//priority_queue<int,vector<int>,greater<int> >qq;
	//priority_queue<int,vector<int>,less<int> >qq;
	int x,t;
	printf("priority_queue<int>qq;      :\n\n");
	for(int i=1;i<=10;i++)
	{
		scanf("%d",&x);
		qq.push(x);
		t=qq.top();
		printf("%d ",t);
	}
	system("pause");
	return 0;
}
