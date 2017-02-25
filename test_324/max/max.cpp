#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int mm=10000+10;
int n,ymax;
struct point
{
	int x,y;
	bool operator<(const point& other)const
	{
		return x<other.x || (x==other.x && y<other.y);
	}
};
point map[mm];
point ans[mm];
int num;
int main()
{
	FILE *fin,*fout;
	fin=freopen("max.in","r",stdin);
	fout=freopen("max.out","w",stdout);
	
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>map[i].x>>map[i].y;
	sort(map+1,map+n+1);
//	for(i=0;i<=n+1;i++)
//		printf("(%d,%d)",map[i].x,map[i].y);
	ymax=map[n].y;
	num++;
	ans[num]=map[n];
//	cout<<n<<endl;
	for(i=n-1;i>=1;i--)
	{
		
		if(map[i].x!=map[i+1].x)
		{
			if(map[i].y>ymax/*map[i+1].y*/)
			{
				num++;
				ans[num]=map[i];
			}
		}
		else
		{
			if(map[i].y>ymax)
			{
				num++;
				ans[num]=map[i];
			}
		}
		if(map[i].y>ymax) ymax=map[i].y;
	}
//	cout<<endl;
	printf("(%d,%d)",ans[num].x,ans[num].y);
	for(i=num-1;i>=1;i--)
	{
		printf(",(%d,%d)",ans[i].x,ans[i].y);
	}
//	cout<<endl<<num<<endl;
	
	fclose(fin);fclose(fout);
	return 0;
}

