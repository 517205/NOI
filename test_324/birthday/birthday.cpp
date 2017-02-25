#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct p
{
	char s[25];
	int birth;
	int len;
};
p a[200];
p tmp[200];
int n,cnt;
int cmp(int x,int y)
{
	int i;
	if(tmp[x].len<tmp[y].len) return 1;
	if(tmp[x].len>tmp[y].len) return 0;
	for(i=0;i<tmp[x].len;i++)
	{
		if(tmp[x].s[i]<tmp[y].s[i]) return 1;
		if(tmp[x].s[i]>tmp[y].s[i]) return 0;
	}
	return 0;
}
void ssort()
{
	int i,j;
	for(i=1;i<cnt;i++)
		for(j=i;j<=cnt;j++)
			if(!cmp(i,j))
				swap(tmp[i],tmp[j]);
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("birthday.in","r",stdin);
	fout=freopen("birthday.out","w",stdout);
	
	cin>>n;
	int i,j,t1,t2;
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i].s);
		a[i].len=strlen(a[i].s);
		cin>>t1>>t2;
		a[i].birth=t1*100+t2;
	}
	int c=0;
	for(i=101;i<=1231;i++)
	{
		cnt=0;
		for(j=1;j<=n;j++)
		{
			if(a[j].birth==i)
			{
				cnt++;
				tmp[cnt]=a[j];
			}
		}
		if(cnt>=2)
		{
			c=1;
			ssort();
			cout<<i/100<<" "<<i%100<<" ";
			for(j=1;j<cnt;j++)
				printf("%s ",tmp[j].s);
			printf("%s\n",tmp[cnt].s);
		}
		
	}
	if(c==0) cout<<"None"<<endl;
	
	fclose(fin);fclose(fout);
	return 0;
}
