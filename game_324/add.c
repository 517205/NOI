#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
int main()
{
    int i=1,max,num,a,b,c1,sum,sum2,ans,c=1,cc=0,ccc;
    int flag=1,x=0;
    time_t start,end;
    printf("��ӭ�μӹ�����ļӷ���Ϸ\n");
    while(cc==0)
    {
    	printf("ѡ��ģʽ������1���̶�������2���Զ���\n");
    	scanf("%d",&x);
    	if(x==1)
    	{
    		num=5;
     		max=100;
     		cc=1;	
		}
		if(x==2)
		{
			printf("��������ĸ�����2��3����");
			scanf("%d",&ccc);			
			printf("����͵����ֵ��");
			scanf("%d",&max);
			printf("����������");
			scanf("%d",&num);
			cc=1;
		}
	}
	while(flag!=0)
	{
		printf("����'0'��ʼ......\n");
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
      				printf("��ȷ��\n");
				}
				else
				{
					printf("���� ��ʧ���ˣ�\n");
					printf("������\n");
					sleep(2000);
					return 0;
				}
			}
			if(i==num+1)
			{	
				printf("������\n");
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
      				printf("��ȷ��\n");
				}
				else
				{
					printf("���� ��ʧ���ˣ�\n");
					printf("������\n");
					sleep(2000);
					return 0;
				}
			}
			if(i==num+1)
			{	
				printf("������\n");
   				sleep(1000);
			}
		}
	} 
	end=time(NULL);
	system("cls");
	double tt=difftime(end,start);
	tt=tt-2;
	printf("��Ӯ�ˣ�\n");
	printf("�㹲����%d���⣡\n",num);
	printf("��ʱ��%.0fs\nƽ����ʱ��%.1fs\n",tt,(double)tt/num);
	while(flag!=0)
	{
		printf("����'0'�˳�......\n");
		scanf("%d",&flag);
	}
	return 0;
}
