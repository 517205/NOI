/*
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int question;
int sum;//sum day
char haab[10];
char useless,useless1;
int hyear,hmon,hday;//haab
int tyear,tday;//tzolkin
//pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
char mon1[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char mon2[21][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int main()
{
	FILE *fin,*fout;
	fin=freopen("calendar.in","r",stdin);
	fout=freopen("calendar.out","w",stdout);
	
	int i,j;
	cin>>question;
	for(i=1;i<=question;i++)
	{
		char mon[10]={""};
        scanf("%d.%s %d",&hday,haab,&hyear);
        for (j=0;j<19;j++)
            if (strcmp(haab,mon1[j])==0) 
                break;
        sum=j*20+hday+hyear*365;
        tday=(sum)%13+1 ;
        tyear=sum/260; 
        j=sum%20;
        printf("%d %s %d\n",tday,mon2[j],tyear);
		
	}
	fclose(fin);fclose(fout);
	return 0;
}

*/

#include<iostream>
using namespace std;
 
int GetMonth(char* month)
{
      int ASCII=0;
      for(int i=0;month[i];i++)
           ASCII+=month[i];
 
      switch(ASCII)
      {
          case 335:return 1;  //pop
           case 221:return 2;  //no
           case 339:return 3;  //zip
           case 471:return 4;  //zotz
           case 438:return 5;  //tzec
           case 345:return 6;  //xul
           case 674:return 7;  //yoxkin
           case 328:return 8;  //mol
           case 414:return 9;  //chen
           case 338:return 10;  //yax
           case 318:return 11;  //zac
           case 304:return 12;  //ceh
           case 305:return 13;  //mac
           case 636:return 14;  //kankin
           case 433:return 15;  //muan
           case 329:return 16;  //pax
           case 534:return 17;  //koyab
           case 546:return 18;  //cumhu
           case 552:return 19;  //uayet
      }
}
int HaabDay(int day,int month,int year)
{
      int sumday=0;
      for(int i=0;i<year;i++) 
           sumday+=365;
 
      for(int j=1;j<month;j++)
           sumday+=20;
 
      return sumday+day;
}
 
int main()
{
      char TzolkinDayName_Str[21][10]={"0","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
      int day;
      char doc;
      char month[10];
      int year;
      int test;
      cin>>test;
      cout<<test<<endl;
      while(test-- && (cin>>day>>doc>>month>>year))  //??. ?? ??
      {
           int sumday=HaabDay(day,GetMonth(month),year);
 
           int TzolkinYear=sumday/260;   //Tzolkin?????260?
           int TzolkinDayName=sumday%20+1;
           int TzolkinDayId=sumday%13+1;
 
           cout<<TzolkinDayId<<' '<<TzolkinDayName_Str[TzolkinDayName]<<' '<<TzolkinYear<<endl;
      }
      return 0;
}

