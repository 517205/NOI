#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[1001];
char s1[150];//text to find
char s2[150];//text to insert
char tmp[150];
int len,ll;
int mem;
void clear()
{
	int j;
	for(j=0;j<ll;j++)
		tmp[j]=' ';
}
int judge()
{
	int i;
//	for(i=1;i<=
//	cout<<memcmp(s2,tmp,sizeof(s2));
//	if(!memcmp(s2,tmp,sizeof(s2))) return 1;
	if(ll!=strlen(tmp)) return 0;
	for(i=0;i<ll;i++)
		if(s1[i]!=tmp[i])
		{
//			cout<<endl<<endl<<s1[i]<<"  "<<tmp[i]<<endl;
			return 0;
		}
	return 1;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("word.in","r",stdin);
	fout=freopen("word.out","w",stdout);
	
	int i,j,first=1,t=0;
	for(i=0;i<150;i++)
		s1[i]=' ';
	
	gets(a);
	scanf("%s%s",s1,s2);
	len=strlen(a);
	a[len]=' ';
	len++;
	ll=strlen(s1);
//	int k=1;
	
	for(i=0;i<len;i++)
	{
//		k=1;
		if(a[i]!=' ')
		{
			tmp[t]=a[i];
			t++;
		}
//		mem=t;
		else
		{
			tmp[t/*+1*/]='\0';
			if(judge())
			{
				t=0;
				if(first==1)
				{
					first=0;
					cout<<s2;
				}
				else
					cout<<" "<<s2;
//				k=0;
			}
			else
			{
				if(first==1)
				{
					first=0;
					for(j=0;j<t;j++)
						cout<<tmp[j];
					t=0;//k=0;
				}
				else
				{
					cout<<" ";
					for(j=0;j<t;j++)
					//	if(tmp[j]!=' ')
							cout<<tmp[j];
					t=0;//k=0;
				}
			}
			clear();
		}
	}
	
//	cout<<endl;
	
//	cout<<endl<<endl;
//	cout<<strlen(tmp);
	
	
	fclose(fin);fclose(fout);
	return 0;
}
