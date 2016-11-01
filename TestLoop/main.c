#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MyPow(int Basic,int N);
double MyPOW(int Num,int N);
double MyPow_double(double Num,int N);
double number_power(const double n,int k);
int main()
{
    /*
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
    printf("%f\n",MyPow_double(10,7));/////Changes
    char Str[]={"Hello World!\n"};
    printf("%s",Str);
    int SumTemp=7103020,n=0;
    while(SumTemp>0)//calculate the bit of a number
    {
        SumTemp/=10;
        n++;
    }
    printf("%d\n",n);
    int double_Bit=sizeof(double);
    int float_Bit=sizeof(float);
    int long_Bit=sizeof(long);
    printf("The bit of the double in this system is :%d\n",double_Bit);
    printf("The bit of the float in this system is :%d\n",float_Bit);
    printf("The bit of the long in this system is :%d\n",long_Bit);
    double double_Num=pow(2,63);
    printf("The double_Num is equal to :%f",double_Num);  */


    double N1 = 1.9409384085814628e+18,N2=2.315017043676e+13;
    double sum = N1+N2;
    printf("The sum is equal to :%f\n",sum);
    int i=0,B=0,n=0;
    double SumTemp=sum,Basic_Wei=14;
    char Symbol[14]={'q','c','7','6','5','O','Z','L','e','v','8','S','I','B'};
    while(SumTemp>0)//calculate the bit of a number
    {
        //SumTemp/=10;
        SumTemp=floor(SumTemp/Basic_Wei);
        n++;
    }
    for(i=0;i<n;i++)
    {
        B=(int)(sum/MyPow_double(Basic_Wei,n-i-1));
        sum-=B*MyPow_double(Basic_Wei,n-i-1);
        printf("%c",Symbol[B]);
    }
    printf("\n");
    double Num=0,temp=0;
    //q c 7 6 5 O Z L e v 8  S  I  B
    //0 1 2 3 4 5 6 7 8 9 10 11 12 13
    //IZvOOL76qL5S8SS8
    printf("The new temp is :%f\n",temp);
    temp=12*MyPow_double(14,15);//I
    Num+=temp;
    printf("The new temp is :%f\n",temp);                      //12*POW(14,15)=1866817146693746688
    //printf("MyPow_double(7,15) is equal to:%f\n",MyPOW(7,15));//POW(14,15)=155568095557812224
    printf("The new temp is :%f\n",temp);
    temp=6*MyPow_double(14,14);//Z
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=9*MyPow_double(14,13);//v
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=5*MyPow_double(14,12);//O
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=5*MyPow_double(14,11);//O
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=7*MyPow_double(14,10);//L
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=2*MyPow_double(14,9);//7
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=3*MyPow_double(14,8);//6
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=0*MyPow_double(14,7);//q
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=7*MyPow_double(14,6);//L
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=4*MyPow_double(14,5);//5
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=11*MyPow_double(14,4);//S
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=10*MyPow_double(14,3);//8
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=11*MyPow_double(14,2);//S
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=11*MyPow_double(14,1);//S
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    temp=10*MyPow_double(14,0);//8
    Num+=temp;
    printf("The new temp is :%f\n",temp);
    printf("The new Num is :%f\n",Num);

    double A=0.0,B1=0.0,C=0.0;
    A=MyPOW(7,15);
    B1=MyPOW(2,15);
    C=A*B1;
    printf("A=MyPOW(7,15) is equal to :%f\n",A);
    printf("B1=MyPOW(2,15) is equal to :%f\n",B1);
    printf("C=A*B is equal to :%f\n",C);

    //POW(14,15)=155568095557812224
    /*double A=0.0,B=0.0;
    A=MyPOW(14,11);
    B=number_power(14,11);
    printf("%f\n",A);
    printf("%f\n",12*A);

    printf("%f\n",B);
    printf("%f\n",12*B); */
    char T;
    scanf("%c",&T);
    printf("%c",T);
    if(T=='y')
    {
        printf("OK!");
    }
    else
    {
        printf("Sorry!");
    }
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
double MyPow_double(double Num,int N)
{
    double Res=1.0;
    int i=0;
    for(i=0;i<N;i++)
    {
        Res*=Num;
    }
    return Res;
}
double MyPOW(int Num,int N)
{
    double Res=1.0,Temp=0.0;
    int i=1;
    while(N!=0)
    {
        Temp=Res;
        for(i=1;i<Num;i++)
        {
            Res+=Temp;
        }
        N--;
    }
    return Res;
}
double number_power(const double n,int k)
{
 static double num=1;
 num=num*n;
 if(k>1)
 {
    k--;
    number_power(n,k);
 }
 return num;
}
