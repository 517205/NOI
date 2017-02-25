#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct apple
    {
        int ch,ma,en,sum,no;
    }stu[51],temp;
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&stu[i].ch,&stu[i].ma,&stu[i].en);
        stu[i].sum=stu[i].ch+stu[i].ma+stu[i].en;
        stu[i].no=i;
    }
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        {
            if(stu[i].sum<stu[j].sum || stu[i].sum==stu[j].sum&&stu[i].no>stu[i].no)
            {
                temp=stu[i];
                stu[i]=stu[j];
                stu[j]=temp;
            }
        }
    for(i=1;i<=n;i++)
    {
        printf("no:%d ch:%d ma:%d en:%d sum:%d\n",stu[i].no,stu[i].ch,stu[i].ma,stu[i].en,stu[i].sum);
    }
     system("pause");
     return 0;
}
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
