#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[10001];
char a[101][51];
int num[101]={0};
char tmp[51];
int word=0;//number of words

void setup()
{
	int i,j;
	for(i=0;i<10001;i++)
		s[i]=' ';
	for(i=0;i<51;i++)
	{
		tmp[i]=' ';
		for(j=1;j<101;j++)
			a[i][j]=' ';
	}
}

int judge()
{
	int i,j,k;
	for(i=0;i<word;i++)
	{
		k=1;
		for(j=0;j<51;j++)
			if(tmp[j]!=a[i][j]) k=0;
		if(k==1) 
		{
//			cout<<"!";
			return 1;
		}
	}
	return 0;
}

int change(int x,int y)
{
	int i;
	for(i=0;i<51/*max(num[x],num[y])*/;i++)//' '=32,'A'=65
	{
		if(a[x][i]>a[y][i])
			return 1;//need change
		if(a[x][i]<a[y][i])
			return 0;
	}
//	return 0;
}

int main()
{
	FILE *fin,*fout;
	fin=freopen("sort.in","r",stdin);
	fout=freopen("sort.out","w",stdout);
	
	setup();
	gets(s);
//	cout<<s<<endl;
	int i,j,t=0,k;
	int l=strlen(s);
	s[l]=' ';
//	cout<<s[l]<<endl;
	l++;
//	cout<<s[l]<<endl;
//	cout<<s<<endl;
	for(i=0;i<=l;i++)
	{
		if(s[i]==' ')
		{
			if(t==0) {}
			else
			{
				t=0;
				if(judge())
				{
					for(j=0;j<51;j++)
						tmp[j]=' ';
					num[word]=0;
				}//Хажи 
				else
				{
					for(j=0;j<num[word];j++)
						a[word][j]=tmp[j];
					for(j=0;j<51;j++)
						tmp[j]=' ';
					word++;
				}
			}
		}
		else
		{
			tmp[t]=s[i];
			t++;
			num[word]++;
		}
	}
	/*
	for(i=0;i<word;i++)
	{
		cout<<num[i]<<"  ";
		for(j=0;j<num[i];j++)
			printf("%c",a[i][j]);
		cout<<endl;
	}
	cout<<word<<endl<<endl;
	*/
	for(i=0;i<word-1;i++)
	{
		for(j=i;j<word;j++)
		{
			if(change(i,j))
			{
				for(k=0;k<51/*max(num[i],num[j])*/;k++)
				{
						char tt=a[i][k];
						a[i][k]=a[j][k];
						a[j][k]=tt;
						int ttt=num[i];
						num[i]=num[j];
						num[j]=ttt;
				}
			}
		}
	}
	for(i=0;i<word;i++)
	{
//		cout<<num[i]<<"  ";
		for(j=0;j<num[i];j++)
			printf("%c",a[i][j]);
		cout<<endl;
	}
	
	fclose(fin);fclose(fout);
	return 0;
}
