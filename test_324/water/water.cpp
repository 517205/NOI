#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct apple
{
	int x,y,p;
	apple(int x=0,int y=0,int p=0):x(x),y(y),p(p){}
};
struct cmp
{
	bool operator()(const apple &a,const apple &b)
	{
		return a.p>b.p;
	}
};

int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,-1,0,1};
int b[20000];
int n,m,sum=0,allsum=0;
int a[101][101];//map
int hash[101][101];
int l=1;

priority_queue<apple,vector<apple>,cmp>qq;

void floodfill(int x,int y)//bfs
{
	int newx,newy;
	int i;
//	int head=0,tail=1;
	while(!qq.empty())
	{
//		head++;
		apple t=qq.top();
		x=t.x;y=t.y;
		
		int cc=1;
		
		for(i=1;i<=4;i++)
		{
			if(x+dx[i]>1 && x+dx[i]<n && y+dy[i]>1 && y+dy[i]<m && hash[x+dx[i]][y+dy[i]]==0)
			{
				cc=0;
				
				qq.pop();//弹出t
				newx=x+dx[i];newy=y+dy[i];
				hash[newx][newy]=1;
				cout<<"#a["<<newx<<"]["<<newy<<"]="<<a[newx][newy]<<endl;
				if(a[newx][newy]>a[x][y])//作为边界 
				{
					qq.push(apple(newx,newy,a[newx][newy]));//入堆 
//					tail++;
					cout<<"<not fill>size:"<<qq.size()<<endl;
				}
				else//灌水 
				{
//					b[l++]=a[newx][newy];//?
					sum+=a[t.x][t.y]-a[newx][newy];//灌水至与最低平齐 
					cout<<"<fill>size:"<<qq.size()<<" sum:+"<<a[t.x][t.y]-a[newx][newy]<<endl;
					a[newx][newy]=a[t.x][t.y];
					qq.push(apple(newx,newy,a[t.x][t.y]));
				}
			}	
		}
		if(cc==1)
		{
			qq.pop();
			cout<<"<fail>size:"<<qq.size()<<" a["<<x<<"]["<<y<<"]"<<endl;
		}
	}
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("water.in","r",stdin);
	fout=freopen("water.out","w",stdout);
	
	int i,j;
	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==1 || i==n || j==1 || j==m)
			{
				qq.push(apple(i,j,a[i][j]));//queue
				hash[i][j]=1;
			}
		}
//	cout<<qq.empty()<<endl<<qq.size()<<endl;
	apple t=qq.top();//qq.pop();
	/*
		printf("\n\n%d %d %d\n\n",t.x,t.y,t.p);

	t=qq.top();qq.pop();
		printf("\n\n%d %d %d\n\n",t.x,t.y,t.p);

	t=qq.top();qq.pop();
		printf("\n\n%d %d %d\n\n",t.x,t.y,t.p);

	t=qq.top();qq.pop();
	printf("\n\n%d %d %d\n\n",t.x,t.y,t.p);
	*/
	floodfill(t.x,t.y);
	
	printf("%d\n",sum);
//	cout<<qq.empty()<<endl;
	fclose(fin);fclose(fout);
	return 0;
}
/*
  Description: POI1999
积水 

问题描述
    有这样一块土地，它可以被划分N*M个正方形小块，每块 
	面积是一平方英寸，第i行第j列的小块可以表示成P(i,j)。
	这块土地高低不平，每一小块地P(i,j)都有自己的高 
	度H(i,j)(单位是英寸)。
    一场倾盆大雨后，由于这块地地势高低不同，许多 
	低洼地方都积存了不少降水。假如你已经知道这块土地的 
	详细信息，你能求出它最多能积存多少立方英寸的降水么?
输入
    输入文件的第一行是两个正整数n和m,1<=n<=100,1<=m<=100,表示 
	土地的尺寸。下面n行，每行m个整数(1..10000);第j行第i个数表示 
	第j行第i列立方体的高。
输出 
	输出文件只有一个数，表示在这个建筑上可以聚合的积水的最大值 
输入输出样例 
输入 
3 6
3 3 4 4 4 2
3 1 3 2 1 4
7 3 1 6 4 1
输出 
5

/////////////////////
failed
#1
******
******
******
#2
******
*0**0*
**-**-
#3____________________________逆向 ，与边相连的拿掉 ，余下统计 
*****-                     -----*       ------
*0*00*                     -*-**-       -*-**-          3个 
**-**-                     --*--*       ------
#4
--***-
-----*
*--**-
#5
------ 
------
*--*--
#6
------
------
*--*--

'0'*5
void set(int x)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>=x)
				t[i][j]=1;
			else t[i][j]=0;
		}
}

解题思路：
不断地去找最低的那个小块进行灌水，这是肯定的。
由于需要一直找最小值，所以用到最小堆来进行优化。
初始化，边界是肯定不能积水的，因为肯定会流出来。
所以在一开始所有的边界都设置为已访问标记。将边界
上所有的点都加进堆里，并不断地调整堆。
在边界中取最低的那一个小块进行扩展，记录这个最小
的节点高度为t ，扩展到的内部节点如果比t小，那么就
灌水，也就是将扩展到的节点高度上升到t，不要忘了统
计ans。并同时将上升后的点加进堆。如果扩展到的点
比t高，也就相当于一个边界，将这个点直接加进堆。
*/
