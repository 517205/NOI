#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100000010;
int w11=0,l11=0,w21=0,l21=0;
int p11[2][maxn];
int p21[2][maxn];
char tmp;
int judgewin(int m,int pp)
{
	if(m==11)
	{
		if(abs(p11[0][pp]-p11[1][pp])>=2 && (p11[0][pp]>=11 || p11[1][pp]>=11))
			return 1;
		return 0;
	}
	if(m==21)
	{
		if(abs(p21[0][pp]-p21[1][pp])>=2 && (p21[0][pp]>=21 || p21[1][pp]>=21))
			return 1;
		return 0;
	}
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("pingpong.in","r",stdin);
	fout=freopen("pingpong.out","w",stdout);
	
	int i11=1,i21=1;
	while(scanf("%c",&tmp)==1)
	{
		if(tmp=='E')
			break;
		else
		{
			if(tmp==87)
			{
				p11[0][i11]++;
				p21[0][i21]++;
				if(judgewin(11,i11))
				{
					i11++;
				}
				
				if(judgewin(21,i21))
				{
					i21++;
				}
			}
			if(tmp==76)
			{
				p11[1][i11]++;
				p21[1][i21]++;
				if(judgewin(11,i11))
				{
					i11++;
				}
				if(judgewin(21,i21))
				{
					i21++;
				}
				
			}	
		}
	}
	int kk=1;
	int i=1;
	while(p11[0][i]!=0 || p11[1][i]!=0)
	{
		kk=0;
		cout<<p11[0][i]<<':'<<p11[1][i]<<endl;
		i++;
	}
	if(kk==0)
		cout<<endl;
	
	
	i=1;
	while(p21[0][i]!=0 || p21[1][i]!=0)
	{
		cout<<p21[0][i]<<':'<<p21[1][i]<<endl;
		i++;
	}
	if(kk==1)
		cout<<"0:0"<<endl<<endl<<"0:0"<<endl;
	
	fclose(fin);fclose(fout);
	return 0;
}
