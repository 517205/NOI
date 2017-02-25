#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
int main()
{
    int i=1,max,num,a,b,c1,sum,sum2,ans,c=1,cc=0,ccc;
    int flag=1,x=0;
    time_t start,end;
    printf("欢迎参加古宜民的加法游戏\n");
    while(cc==0)
    {
    	printf("选择模式：输入1，固定；输入2，自定义\n");
    	scanf("%d",&x);
    	if(x==1)
    	{
    		num=5;
     		max=100;
     		cc=1;	
		}
		if(x==2)
		{
			printf("输入加数的个数（2或3）：");
			scanf("%d",&ccc);			
			printf("输入和的最大值：");
			scanf("%d",&max);
			printf("输入题数：");
			scanf("%d",&num);
			cc=1;
		}
	}
	while(flag!=0)
	{
		printf("输入'0'开始......\n");
		scanf("%d",&flag);
	}
	flag=1;
	system("cls");
	srand((unsigned)time(0));
	start=time(NULL);	
	while(i<=num)	
	{
		a=rand()%(max+1);b=rand()%(max+1);c1=rand()%(max+1);
		sum=a+b;
		sum2=a+b+c1;
		if(ccc==2)
		{
			if(sum<=max)
			{
				i++;
				c=1;
			}
			else c=0;
			if(c==1)
			{
				printf("%d+%d=",a,b);
				scanf("%d",&ans);
				if(ans==sum)
				{
      				printf("正确！\n");
				}
				else
				{
					printf("错误！ 你失败了！\n");
					printf("结束！\n");
					sleep(2000);
					return 0;
				}
			}
			if(i==num+1)
			{	
				printf("结束！\n");
   				sleep(1000);
			}
		}	
			
			
		if(ccc==3)
		{
			if(sum2<max)
			{
				i++;
				c=1;
			}
			else c=0;
			if(c==1)
			{
				printf("%d+%d+%d=",a,b,c1);
				scanf("%d",&ans);
				if(ans==sum2)
				{
      				printf("正确！\n");
				}
				else
				{
					printf("错误！ 你失败了！\n");
					printf("结束！\n");
					sleep(2000);
					return 0;
				}
			}
			if(i==num+1)
			{	
				printf("结束！\n");
   				sleep(1000);
			}
		}
	} 
	end=time(NULL);
	system("cls");
	double tt=difftime(end,start);
	tt=tt-2;
	printf("你赢了！\n");
	printf("你共算了%d道题！\n",num);
	printf("用时：%.0fs\n平均用时：%.1fs\n",tt,(double)tt/num);
	while(flag!=0)
	{
		printf("输入'0'退出......\n");
		scanf("%d",&flag);
	}
	return 0;
}
