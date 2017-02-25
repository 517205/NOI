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
				
				qq.pop();//����t
				newx=x+dx[i];newy=y+dy[i];
				hash[newx][newy]=1;
				cout<<"#a["<<newx<<"]["<<newy<<"]="<<a[newx][newy]<<endl;
				if(a[newx][newy]>a[x][y])//��Ϊ�߽� 
				{
					qq.push(apple(newx,newy,a[newx][newy]));//��� 
//					tail++;
					cout<<"<not fill>size:"<<qq.size()<<endl;
				}
				else//��ˮ 
				{
//					b[l++]=a[newx][newy];//?
					sum+=a[t.x][t.y]-a[newx][newy];//��ˮ�������ƽ�� 
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
��ˮ 

��������
    ������һ�����أ������Ա�����N*M��������С�飬ÿ�� 
	�����һƽ��Ӣ�磬��i�е�j�е�С����Ա�ʾ��P(i,j)��
	������ظߵͲ�ƽ��ÿһС���P(i,j)�����Լ��ĸ� 
	��H(i,j)(��λ��Ӣ��)��
    һ�����������������ص��ƸߵͲ�ͬ����� 
	���ݵط��������˲��ٽ�ˮ���������Ѿ�֪��������ص� 
	��ϸ��Ϣ���������������ܻ����������Ӣ��Ľ�ˮô?
����
    �����ļ��ĵ�һ��������������n��m,1<=n<=100,1<=m<=100,��ʾ 
	���صĳߴ硣����n�У�ÿ��m������(1..10000);��j�е�i������ʾ 
	��j�е�i��������ĸߡ�
��� 
	����ļ�ֻ��һ��������ʾ����������Ͽ��ԾۺϵĻ�ˮ�����ֵ 
����������� 
���� 
3 6
3 3 4 4 4 2
3 1 3 2 1 4
7 3 1 6 4 1
��� 
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
#3____________________________���� ������������õ� ������ͳ�� 
*****-                     -----*       ------
*0*00*                     -*-**-       -*-**-          3�� 
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

����˼·��
���ϵ�ȥ����͵��Ǹ�С����й�ˮ�����ǿ϶��ġ�
������Ҫһֱ����Сֵ�������õ���С���������Ż���
��ʼ�����߽��ǿ϶����ܻ�ˮ�ģ���Ϊ�϶�����������
������һ��ʼ���еı߽綼����Ϊ�ѷ��ʱ�ǡ����߽�
�����еĵ㶼�ӽ���������ϵص����ѡ�
�ڱ߽���ȡ��͵���һ��С�������չ����¼�����С
�Ľڵ�߶�Ϊt ����չ�����ڲ��ڵ������tС����ô��
��ˮ��Ҳ���ǽ���չ���Ľڵ�߶�������t����Ҫ����ͳ
��ans����ͬʱ��������ĵ�ӽ��ѡ������չ���ĵ�
��t�ߣ�Ҳ���൱��һ���߽磬�������ֱ�Ӽӽ��ѡ�
*/
