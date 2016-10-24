#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getline_ex(char s[],int lim);
int main()
{
    int N,i=0,j=0,k=0;
    scanf("%d",&N);
    char Simble[N];
    for(i=0;i<N-1;i++)
    {
        scanf("%c",&Simble[i]);
    }
    char A,B;
    char *Plus1=&A,len1,flag1,*Plus2=&B,len2,flag2;
    len1=getline_ex(Plus1,1000);
    len2=getline_ex(Plus2,1000);
    for(j=0;j<len1;j++)//search the true plus1
    {
        if(*(Plus1+j)==" ") flag1++;
    }
    Plus1=Plus1+flag1;
    Plus2=Plus2+1;
    char *String;
    getline_ex(String,100);
    getline_ex(String,100);
    int N_bit=len1-flag1-1,Num1=0;
    for(j=0;j<N_bit;j++)
    {
        for(i=0;i<N-1;i++)
        {
            if(*(Plus1+j)==Simble[i]) Decimal[j]=i;
        }
        Num1+=pow(10,N_bit-1)*Decimal[j];
    }
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
    }
    while(i<lim);
    s[i]='\0';
    return i;
}
