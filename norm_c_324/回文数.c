#include<stdio.h>
int a[200]={0};
int A=1000000000;
int main()
{
    int i=1,n1=0,n2=0,r1=1,r2=1,x=0,x1=0,j=1,y=0,k=1,c=1;
	scanf("%d",&x);
	y=x;x1=x;
	for(i=1;i<A;i++)
	{
        y=x1;r1=1;r2=1;n1=0;n2=0;
        if(x1>=A)
        {
        printf("x1=%d\n",x1);
        printf("Failed\n");
        break;
        }
	    //OK
        for(k=1;k<=20;k++)
	    {
	        y=y/10;
            if(y==0) break;
        }
        printf("It has %d numbers\n",k);
		y=x1;
		printf("y=x1=%d\n",y);
        //OK
  	    for(j=1;j<=k;j++)
	    {
            a[j]=(y/r1)%10;
            r1=r1*10;
        }
        //OK
        for(j=1;j<=k;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
        //OK
 		c=1;
        printf("c=%d\n",c);
		for(j=1;j<=k/2;j++)
		{
			if(a[j]!=a[k-j+1])
			{
             c=0;
             break;
            }
        }
        printf("c=%d\n",c);
        if(c==1)
        {
        	printf("\n%d\n",x1);
        	break;
        }
        //OK
        for(j=1;j<=k;j++)
        {
        	n1=n1+a[j]*r2;
        	n2=n2+a[k-j+1]*r2;
        	r2=r2*10;
       	}
       	x1=n1+n2;
       	printf("n1=%d n2=%d x1=%d\n",n1,n2,x1);
       	printf("\n");
	}
	//printf("\n");
	system("pause");
	return 0;
}


	
 		
 		
 		
 		
 		
		
