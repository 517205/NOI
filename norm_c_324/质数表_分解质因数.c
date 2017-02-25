#include<stdio.h>
#include<math.h>
#include<time.h>
int a[46000]={0};
int a1[46000]={0};
int main()
{
	int i=0,j=0,k=1,t=1,m=0;
    for(i=2;i<46000;i++)
        a[i]=1;
    a[1]=0;a[0]=0;
    for(i=1;i<sqrt(46000)+1;i++)
    {
        j=j+1;
        for(j=m++;a[j]==0;j++){}
        for(k=1+j;k<46000;k++)
        	if(k%j==0)
            	a[k]=0;
    }
    for(i=1;i<46000;i++)
        if(a[i]!=0)
            a1[t++]=i;
            
            
            

	int x=0,sum=0;

	while(x!=1)
	{
	scanf("%d",&x);	
	int x1=x;
	for(i=1;a1[i]<sqrt(x)+1;i++)
	{
		while(x1%a1[i]==0 && x1!=1)
		{
			x1=x1/a1[i];
			printf("%d  ",a1[i]);
			sum++;
		}
		if(x1==1) break;
	}
	if(x1!=1)
		printf("%d  ",x1);
			

    printf("\nTime used:%0.2f\n",(double)clock()/CLOCKS_PER_SEC);
    system("pause");
    
    }
    return 0;
}

    //for(i=1;i<3200,a1[i]!=0;i++)
        //printf("%d  ",a1[i]);
		//	system("pause");


/*void t1()
{
    int i=0,j=0,k=1,t=1,m=0;
    for(i=2;i<3200;i++)
        a[i]=1;
    a[1]=0;a[0]=0;
    for(i=1;i<sqrt(3200)+1;i++)
    {
        j=j+1;
        for(j=m++;a[j]==0;j++){}
        for(k=1+j;k<3200;k++)
        	if(k%j==0)
            	a[k]=0;
    }
    for(i=1;i<3200;i++)
        if(a[i]!=0)
            a1[t++]=i;
}Press any key to continue . . .
*/
