//#include<iostream>
//#include<cstdio>
//using namespace std;
#include<stdio.h>

#define M 2001
//int inter[1000001];//interactions
//1=same 0=different
int father[M],differ[M];

int find(int v)
{
 		int f;
 		if(v==father[v])
 		{
//				differ[v]=0;
		 		return v;
		}
		f=father[v];
 		father[v]=find(father[v]);
// 		differ[v]=0;//(differ[father[v]]+1)%2
		differ[v]=(differ[v]+differ[f])%2;
 		return father[v];
}
int main()
{
    FILE *fin,*fout;
		fin=freopen("bug.in","r",stdin);
		fout=freopen("bug.out","w",stdout);
		
		int sum,num,x,y,inter,fx,fy,flag=0,c=1;
		int i,j;
		scanf("%d",&sum);
		for(i=1;i<=sum;i++)
		{
				for(j=1;j<M;j++)
				{
						father[j]=j;
						differ[j]=1;
				}
				printf("Scenario #%d:\n",i);
        scanf("%d%d",&num,&inter);
        for(j=1;j<=inter;j++)
        {
						scanf("%d%d",&x,&y);
						fx=find(x);
						fy=find(y);
						if(fx==fy)
								if(differ[x]==differ[y])
								{
										flag=1;
										break;
								}
						if(fx!=fy)
						{
								father[fy]=fx;		
								if(differ[x]==0 && differ[y]==0) differ[fx]=0;
								if(differ[x]==0 && differ[y]==1) differ[fx]=1;
								if(differ[x]==1 && differ[y]==0) differ[fx]=1;
								if(differ[x]==1 && differ[y]==1) differ[fx]=0;
					  	}	
				}
/*				for(j=1;j<=num;j++)
				{
						if(differ[father[j]]==differ[j])
								flag=1;
				}
*/
//				for(j=1;j<=num+1;j++)
//						printf("%2d",father[j]);
//				printf("\n");
//				for(j=1;j<=num+1;j++)
//						printf("%2d",differ[j]);
//				printf("\n");
				if(flag==1)
						printf("Suspicious bugs found!\n\n");
				if(flag==0)
						printf("No suspicious bugs found!\n\n");
				flag=0;	
		}
		fclose(fin);fclose(fout);
		return 0;
}
				
//				printf("repacement of %d is OK!\n",i);
        
//        printf("%d is OK!\n",i);
//				printf("i=%d start! Sum=%d\n",i,sum);        			
/*						if(fx==fy)
						{
								printf("Suspicious bugs found!\n\n");
								c=0;
								break;
						}
*/	
