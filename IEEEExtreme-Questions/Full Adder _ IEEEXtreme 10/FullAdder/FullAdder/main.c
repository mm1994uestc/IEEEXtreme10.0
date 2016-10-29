/********************************************************
  It's seem that the IEEE Xtreme Competition Platform can
  not call the basic function free().So if you are try to
  run this code on the platform.please notice this problem.
  You need to common the free() function line in order to
  run this program.Also there are some problems while run-
  ing.I thank that may be the integer is too small to storage
  the number calculated in the program.So I will try to
  modify this later.  Time:20161025  Edited by:Miao Ma.
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getline_ex(char s[],int lim);
int MyPow(int Basic,int N);
int main()
{
    int i=0,j=0,k=0,Basic_Len=0,Basic_Wei=0;
    char *Basic_info=(char *)malloc(sizeof(char)*25);//Allocate some MEM to Record the basic information of input
    Basic_Len=getline_ex(Basic_info,25);//Get the input information to the memory.
    for(i=0;i<Basic_Len;i++)//Get the length of Basic information.
    {
        if(*(Basic_info+i)==' ') break;
    }
    for(k=0;k<i;k++)//Get the basic radix.
    {
        Basic_Wei+=(((int)*(Basic_info+k)-48))*MyPow(10,i-k-1);//calculate the weight of the Numerical system.
    }
    char *Symbol=(char *)malloc(sizeof(char)*(Basic_Len-2-i));//Allocate some memory to storage the Symbol system.
    for(j=0;j<Basic_Len-1-i;j++)//Get the values of true symbols.
    {
        *(Symbol+j)=*(Basic_info+j+i+1);
    }

    char *Plus1=(char *)malloc(sizeof(char)*20),len1=0,flag1=0;
    char *Plus2=(char *)malloc(sizeof(char)*20),len2=0,flag2=0;
    len1=getline_ex(Plus1,20);
    len2=getline_ex(Plus2,20);
    char *Plus1_Out=(char *)malloc(sizeof(char)*20);
    Plus1_Out=Plus1;
    char *Plus2_Out=(char *)malloc(sizeof(char)*20);
    Plus2_Out=Plus2;
    for(j=0;j<len1;j++)//search the true plus1
    {
        if(*(Plus1+j)==' ') flag1++;
    }
    Plus1=Plus1+flag1;
    for(j=0;j<len2;j++)//search the true plus1,note that the Plus2 is begin with a symbol:'+'
    {
        if(*(Plus2+j)==' ') flag2++;
    }
    Plus2=Plus2+1+flag2;

    char *String1=(char *)malloc(sizeof(char)*20);
    char *String2=(char *)malloc(sizeof(char)*20);
    getline_ex(String1,20);//is useful when you are going to output the result!
    getline_ex(String2,20);
    free(String2);//Just use to get the input string!

    int N1_bit=len1-flag1;
    long Num1=0;//Notice the Num1's init value.
    for(j=0;j<N1_bit;j++)//change the number into Decimal type!
    {
        for(i=0;i<Basic_Wei-1;i++)//
        {
            if(*(Plus1+j)==*(Symbol+i)) break;//
        }
        Num1+=i*MyPow(Basic_Wei,N1_bit-j-1);//calculate the first decimal.
    }
    free(Plus1);

    int N2_bit=len2-flag2-1;
    long Num2=0;//Notice the Num2's init value.
    for(j=0;j<N2_bit;j++)//change the number into Decimal type!
    {
        for(i=0;i<Basic_Wei-1;i++)//
        {
            if(*(Plus2+j)==*(Symbol+i)) break;
        }
        Num2+=i*MyPow(Basic_Wei,N2_bit-j-1);//calculate the second decimal.
    }
    free(Plus2);
    long sum=Num1+Num2;
    //printf("%d\n",sum);

    //char Str[20];
    long SumTemp=sum;
    int n=0;
    while(SumTemp>0)//calculate the bit of a number
    {
        //SumTemp/=10;
        SumTemp/=Basic_Wei;
        n++;
    }
    //printf("%d\n",n);//
    printf("%s\n",Basic_info); free(Basic_info);
    printf("%s\n",Plus1_Out); free(Plus1_Out);
    printf("%s\n",Plus2_Out); free(Plus2_Out);
    printf("%s\n",String1); free(String1);
    printf(" ");
    long B=0;
    for(i=0;i<n;i++)
    {
        B=sum/MyPow(Basic_Wei,n-i-1);
        sum-=B*MyPow(Basic_Wei,n-i-1);
        //printf("Now,The Res of B:%d\n",B);
        //Str[i]=*(Symbol+B);
        printf("%c",*(Symbol+B));
    }
    free(Symbol);
    return 0;
}
int getline_ex(char s[],int lim){
    int c=getchar();
    int i=0;
    do{
        if (c!='\n'&&c!=EOF) {
            s[i++] = c;
        }
        c=getchar();
        if (c=='\n'||c==EOF) {
            break;
        }
    }while(i<lim);
    s[i]='\0';
    return i;
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
