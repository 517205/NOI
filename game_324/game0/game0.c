#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define M 80
int  a[85][85]={0};
int flag1=1;
int flag[85][85]={0};
int M=40,N=50;
/*
struct HASH
{
	int map[85][85];
}hash[];
*/
void print(int x)
{
	int i,j;
	if(x==3)
	for(i=1;i<=N;i++)
	{
	    for(j=1;j<=M;j++)
	    {
			if(a[i][j]==1) printf("��");
			else printf("��");
		}
	}
	if(x==2)
	for(i=1;i<=N;i++)
	{
	    for(j=1;j<=M;j++)
	    {
			if(a[i][j]==1) printf("O");
			else printf("-");
		}
	}
	if(x==1)
	for(i=1;i<=N;i++)
	{
	    for(j=1;j<=M;j++)
	    {
			if(a[i][j]==1) printf("1");
			else printf("0");
		}
	}
}

void judgeall()
{
	int i,j,c=1;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
		    if(a[i][j]==1)
		        c=0;
	if(c==1)
		flag1=0;
}

/*
int judge(int x,int y)
{
	if(x<=23 && x>=2 && y<=M-1 && y>=2)
	    return 1;
	else return 0;
}
*/
void random()
{
	srand((unsigned)time(0));
	int i,j,aa,b,c,d,z;
	printf("ѡ���������:1--1/4,2--1/2,3--3/4\n");
	scanf("%d",&z);
	for(i=1;i<=N;i++)
	    for(j=1;j<=M;j++)
	    {
			
				aa=rand()%2;
				b=rand()%2;
				c=rand()%2;
				d=rand()%2;
					if(z==1)
						if(aa==1 && b==1 && c==1 && d==1)
							a[i][j]=1;
					if(z==2)
						if(aa==1 && b==1)
							a[i][j]=1;
					if(z==3)
						if(aa==1 || b==1)
							a[i][j]=1;						

//				a[i][j]=0;
		}
}

void clear()
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			flag[i][j]=0;
}
int ran()
{
	int a=rand()%2;
	int b=rand()%2;
	if(a==1 && b==1) return 1;
	else return 0;
}

int main()
{
	FILE *fin;
	fin=fopen("game0.in","r");
//	sleep(1000);
	int c,f;

	printf(" ������Ϸ��ʵ��һ���������Ϸ��������һ����ά�������磬��������е�ÿ�������ס��һ�����ŵĻ����˵�ϸ����һ��ϸ������һ��ʱ������ȡ�������ڰ˸������л��ŵĻ����˵�ϸ����������������ڷ�����ŵ�ϸ���������࣬���ϸ������Ϊ��Դ�ѷ�������һ��ʱ����ȥ���෴�������Χ��ϸ�����٣����ϸ������̫�µ�����ȥ��ÿ�����ӵ�������ѭ�����ԭ�򣺡���\n1�� ���һ��ϸ����Χ��3��ϸ��Ϊ����һ��ϸ����Χ����8��ϸ���������ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩 ������\n2�� ���һ��ϸ����Χ��2��ϸ��Ϊ�������ϸ��������״̬���ֲ��䣻\n3�� ����������£���ϸ��Ϊ���� \n\n"); 
	system("color 02");
	printf("ѡ�����:1--'0''1',2--'-''O',3--'��'��'");
	scanf("%d",&f);
	printf("ѡ���ģ:1--half screen,2--full screen\n");
	scanf("%d",&c);
	if(f==3)
	{
		if(c==1){M=40;N=24;}
		if(c==2){M=40;N=50;}
	}
	if(f==1 || f==2)
	{
		if(c==1){M=80;N=24;}
		if(c==2){M=80;N=50;}
	}		
	printf("ѡ��ʽ:1--random,2--fixed\n");
	scanf("%d",&c);
    int x,i,j,x1,y1;
    
	if(c==2)
	{


    	fscanf(fin,"%d",&x);
    	for(i=1;i<=x;i++)
    	{
        	fscanf(fin,"%d%d",&x1,&y1);
        	a[x1][y1]=1;
    	}
/*
		for(i=1;i<=24;i++)
		    for(j=1;j<=M;j++)
		        fscanf(fin,"%d",&a[i][j]);
*/
	    system("cls");

	}

	if(c==1) random();
	
	system("cls");
    while(flag1)
    {
		judgeall();
		print(f);
		clear();
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
								
				if(a[i+1][j+1]==1) flag[i][j]++;
				if(a[i+1][j]==1) flag[i][j]++;
				if(a[i+1][j-1]==1) flag[i][j]++;
				if(a[i][j+1]==1) flag[i][j]++;
				if(a[i][j-1]==1) flag[i][j]++;
				if(a[i-1][j-1]==1) flag[i][j]++;
				if(a[i-1][j+1]==1) flag[i][j]++;
				if(a[i-1][j]==1) flag[i][j]++;
				
			}
		}
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				if(flag[i][j]==3) a[i][j]=1;
				if(flag[i][j]!=2 && flag[i][j]!=3) a[i][j]=0;				
			}
		}
//		sleep(1000);
		system("pause");
		system("cls");
		


    }
    
	printf("end!\n");

    system("pause");
    fclose(fin);
    return 0;
}
