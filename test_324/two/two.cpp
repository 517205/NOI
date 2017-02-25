#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
//longlong 2^63-1 19
int n;
const int a[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
//     2^        0 1 2 3 4  5  6  7   8   9   10   11   12   13   14
void print(int x,int flag)//flag==1----' ' flag==0----'+ '
{
    int i,t=x,f=flag;
    for(i=14;i>=0;i--)
    {
        if(t>a[i])
        {
            t-=a[i];
            
            if(flag==0)
                printf("+");
            
            if(i==1) printf("2");
            else if(i==0) printf("2(0)");
            else
            {
                printf("2(");
                print(i,1);
                printf(")");
            }
            
            printf("+");
            print(t,1);
            
            break;
        }
        if(t==a[i])
        {
            if(i==0)
            {
                printf("2(0)");
                break;
            }
            if(i!=1)
            {
                if(flag==0)
                    printf("+");
                printf("2(");
                print(i,1);
                printf(")");
                break;
            }
            if(i==1)
            {
                if(flag==0)
                    printf("+");
                printf("2");
                break;
            }
        }
    }
     
     
     
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("two.in","r",stdin);
	fout=freopen("two.out","w",stdout);
	
	cin>>n;
	print(n,1);
	cout<<endl;
	
		
	fclose(fin);fclose(fout);
	return 0;
}
