#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double l,l2,n,c;
double ans;

int main()
{
	FILE *fin,*fout;
	fin=freopen("stick.in","r",stdin);
	fout=freopen("stick.out","w",stdout);

	int i,j;
 	scanf("%lf%lf%lf",&l,&n,&c);
	l2=(1+n*c)*l;
	double le=0.0,ri=asin(1.0),mid=(le+ri)/2;
    while(ri-le>1e-12)
    {
        mid=(ri+le)/2;
        if(l2*sin(mid)/mid<=l)
        	ri=mid;
        else
        	le=mid;
    }

    printf("%.3lf\n", l/2*tan(le/2));
	fclose(fin);fclose(fout);
	return 0;
}
/*TLE
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double l,l2,n,c;
double r;
double ans;
double e=0.000000000001;
int judge(double rr)
{
	double tt=l2/(2*rr);
	while(tt>6.28318530717) tt=tt-6.28318530717;
	double x1=l/(2*rr);
	double x2=sin(tt);
	double xx=x2-x1;
//	printf("rr=%f x1=%f x2=%f\n",rr,l,l2,x1,x2);
	if(xx>e) return 1;
	if(xx<-e) return -1;
	return 0;
}
int main()
{
	FILE *fin,*fout;
	fin=freopen("stick.in","r",stdin);
	fout=freopen("stick.out","w",stdout);
	
	int i,j;
 	scanf("%lf%lf%lf",&l,&n,&c);
//	printf("%f %f %f",l,n,c);
	l2=(1+n*c)*l;
//	printf(" %f\n",l2);
	double le=0.000000001,ri=100000000,mid=(le+ri)/2;
//	printf("%f\n",ri);
//	printf("%f\n",mid);
	int lflag=-1,rflag=1,mflag;
//	printf("%d\n",judge(mid));
	while(judge(mid)!=0)
	{
		mflag=judge(mid);
		if(mflag==lflag) le=mid;
		else ri=mid;
		mid=(ri+le)/2;
//		printf("mid=%f %d\n",mid,mflag);
		
		
		
		
	}
	r=mid;
	
	
	
	ans=r*(1-sqrt(1-l*l/(4*r*r)));
	printf("%.3f\n",ans);
//	printf("%f",sin(3.1415926*4));
	fclose(fin);fclose(fout);
	return 0;
}
//sin asin(arcsin)
*/
