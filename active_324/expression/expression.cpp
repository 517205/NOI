#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[1010];
int point,len;//yes==0,true
int calc()
{
	int yes=1,tmp=0;
	int ope;//|,&,!---1,2,3
	for(;point<=len;point++)
	{
		if(s[point]=='V')
		{
			tmp=1;
			if(ope==1)
			{
				return 1;//always ture
			}
			if(ope==2)
			{
				//null
			}
			if(ope==3)
			{
				tmp=!tmp;
			}
			continue;
		}
		if(s[point]=='F')
		{
			tmp=0;
			if(ope==1)
			{
				//null
			}
			if(ope==2)
			{
				return 0;//always false
			}
			if(ope==3)
			{
				tmp=!tmp;
			}
			continue;
		}
		if(s[point]=='|')
		{
			ope=1;
			continue;
		}
		if(s[point]=='&')
		{
			ope=2;
			continue;
		}
		if(s[point]=='!')
		{
			ope=3;
			continue;
		}
		if(s[point]=='(')
		{
			tmp=calc();
			continue;
		}
		if(s[point]==')')
			return yes;
	}
    
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("expression.in","r",stdin);
	fout=freopen("expression.out","w",stdout);
	
	int c=1;
	while(c)
	{
		point=0;
        char tmp=' ';
        int len=0,i,j,judge=0;
        memset(s,0,sizeof(s));
        while(tmp!='\n')
        {
			if(judge>1000)
			{
				c=0;
				break;
			}
			scanf("%c",&tmp);
            if(tmp==' ')
			{
				judge++;
				continue;
			}
            len++;
            s[len]=tmp;
        }
        len--;//except '\n'  1<=~<=len
		for(i=1;i<=len;i++) cout<<s[i];
		cout<<endl;
		
		
		cout<<calc()<<endl;
		
		
		
		
    }
	fclose(fin);fclose(fout);
	return 0;
}
