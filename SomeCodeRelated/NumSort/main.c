#include <stdio.h>
#include <stdlib.h>

void MySwap(char *Num1,char *Num2);
void Bubble(char *Seq,int L);
int getline_ex(char s[],int lim);
int main()
{
    printf("Please enter some number with space separated for calculate:");
    char Number[1000]={'0'};
    int Count=0,N=0,i=0,j=0;
    Count=getline_ex(Number,1000);
    N=(Count+1)/2;
    char Num[N];
    for(i=0;i<N;i++)
    {
        Num[i]=Number[j];
        j+=2;
    }
    Bubble(Num,N);
    for(i=0;i<N;i++)
    {
        printf("%c",Num[i]);
    }
    printf("\n");
    printf("The middle of the sequence is:%c",Num[(N-1)/2]);
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
void Bubble(char *Seq,int L)
{
    int i=0,j=0;
    for(i=0;i<L;i++)
    {
        for(j=i;j<L;j++)
        {
            if(*(Seq+i)>=*(Seq+j)) MySwap(Seq+i,Seq+j);
        }
    }
}
void MySwap(char *Num1,char *Num2)
{
    char Temp=0;
    Temp=*Num1;
    *Num1=*Num2;
    *Num2=Temp;
}
