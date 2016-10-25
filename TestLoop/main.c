#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MyPow(int Basic,int N);
int main()
{
    int Basic_Wei=10,i=0,j=0;
    char *Plus1="752";
    char *Symbol="0123456789";
    int N1_bit=3,Num1=0;//Notice the Num2's init value.
    for(j=0;j<N1_bit;j++)//change the number into Decimal type!
    {
        for(i=0;i<Basic_Wei-1;i++)//
        {
            if(*(Plus1+j)==*(Symbol+i)) break;
        }
        Num1+=i*MyPow(Basic_Wei,N1_bit-j-1);//calculate the second decimal.
    }
    printf("Result is :%d\n",Num1);
    printf("%d",MyPow(10,7));
    char Str[]={"Hello World!"};
    printf("%s",Str);
    int SumTemp=7103020,n=0;
    while(SumTemp>0)//calculate the bit of a number
    {
        SumTemp/=10;
        n++;
    }
    printf("%d",n);
    return 0;
}
int MyPow(int Basic,int N)
{
    int i=0,Res=1;
    for(i=0;i<N;i++)
    {
        Res*=Basic;
    }
    return Res;
}
