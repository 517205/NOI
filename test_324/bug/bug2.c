#include<stdio.h>
//0=same,1=differ
int f[2005],r[2005];
int fs(int i)
{
if(f[i]==i)
   return i;
int t=f[i];
f[i]=fs(f[i]);                //·��ѹ��������ʹf[i]ֱ��ָ�����µĸ��ڵ�
//����������µĸ��ڵ㣨���������ȣ�r[t]���ϵĸ��ڵ�������µĸ��ڵ㣨����������
//��r[i]��iԪ��������ϵĸ��ڵ���ȣ�
//�����������������˶����õ���r[i]����������µĸ��ڵ㣨���������ȡ���������ݹ���ò��ᳬ�����㡣
r[i]=(r[t]+r[i])%2; 
return f[i];
}

void un(int x,int y)//union
{
int a=fs(x),b=fs(y);
f[a]=b;
r[a]=(r[y]-r[x]+1)%2;       //r[a]+r[x]��r[y]������µĸ��ڵ�������1���ȼ�����Ϊ���ǲ���gay
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cases,n,m,i,k,x,y;
	scanf("%d",&cases);
	for(k=1;k<=cases;k++)
	{
   		int flag=0;
   		scanf("%d %d",&n,&m);
   		for(i=1;i<=n;i++)
   		{
    		f[i]=i;
    		r[i]=0;
   		}
   for(i=1;i<=m;i++)
   {
    scanf("%d %d",&x,&y);
    if(fs(x)==fs(y))
    {
     if(r[x]!=(r[y]+1)%2)
      flag=1;
    }
    else
     un(x,y);
   }
   if(flag)
    printf("Scenario #%d:\nSuspicious bugs found!\n\n",k);
   else
    printf("Scenario #%d:\nNo suspicious bugs found!\n\n",k);
	
 
 
 //	system("pause");
 }
//system("pause");
return 0;
}
