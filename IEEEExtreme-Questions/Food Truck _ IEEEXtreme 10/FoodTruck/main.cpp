#include <iostream>

using namespace std;

static int Time_Compare(char N1,char *Time1,char N2,char *Time2);
int main()
{
    char Data[30][50]={{0,},};
    int Recently=0;
    cout << "Hello world!" << endl;
    Recently=Time_Compare(10,Data[10],12,Data[12]);
    return 0;
}

static int Time_Compare(char N1,char *Time1,char N2,char *Time2)
{
    int year_com=(*(Time1+6)-*(Time2+6))*1000+(*(Time1+7)-*(Time2+7))*100+(*(Time1+8)-*(Time2+8))*10+*(Time1+9)-*(Time2+9);
    if(year_com>0)  return N1;
    if(year_com>0)  return N2;
    int month_com=(*(Time1+3)-*(Time2+3))*10+*(Time1+4)-*(Time2+4);
    if(month_com>0) return N1;
    if(month_com<0) return N2;
    int day_com=(*(Time1)-*(Time2))*10+*(Time1+1)-*(Time2+1);
    if(day_com>0)   return N1;
    if(day_com<0)   return N2;
    int hour_com=(*(Time1+11)-*(Time2+11))*10+*(Time1+12)-*(Time2+12);
    if(hour_com>0)   return N1;
    if(hour_com<0)   return N2;
    int minu_com=(*(Time1+14)-*(Time2+14))*10+*(Time1+15)-*(Time2+15);
    if(minu_com>0)   return N1;
    if(minu_com<0)   return N2;
    return N2;
}
