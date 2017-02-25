#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <sstream>
using namespace std;
set <int> a;
set <int>::iterator it;
int i,x;
int main()
{
    a.insert(5);
	a.insert(100); 
    a.insert(7);
	a.insert(5);
	a.insert(8);
    a.insert(100);
	a.insert(100);
    int n=a.size();
    printf("5,100,7,5,8,100,100\n");
	printf("a.size--%d\n",n); 
    printf("5--%d\n",a.count(5));
    printf("7--%d\n",a.count(7));
    printf("8--%d\n",a.count(8));
    printf("6--%d\n",a.count(6));
    printf("100--%d\n",a.count(100));
    printf("a.empty--%d\n\n",a.empty());
    while (!a.empty()) 
	{                          
    	scanf("%d",&x);
        if ( (it=a.find(x)) != a.end())
			a.erase(it);
		printf("a.size--%d\n",a.size());
		printf("5--%d\n",a.count(5));
    	printf("7--%d\n",a.count(7));
    	printf("8--%d\n",a.count(8));
    	printf("6--%d\n",a.count(6));
    	printf("100--%d\n",a.count(100));
    	printf("a.empty--%d\n\n",a.empty());
    }
    n=a.size();
    printf("n--%d\n",n);
    system("pause");
    return 0;
}
