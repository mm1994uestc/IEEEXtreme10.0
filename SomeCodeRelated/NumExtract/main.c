#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7
void ShowFunc1(void);
void ShowFunc2(void);
int main()
{
    char Number[N]={'0'};
    int i=0,j=0;
    scanf("%s",Number);
    for(i=0;i<N;i++)
    {
        printf("%c",*(Number+i));
    }
    printf("\n");
    ShowFunc1();
    ShowFunc2();
    //printf("%s",Number);
    int Array_Ori[5][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}},Array_Res[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            Array_Res[i][j]=Array_Ori[4-i][4-j];
            printf("%d ",Array_Res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void ShowFunc1(void)
{
    int i=0;
    char *Str;
    for(i=0;i<7;i++)
    {
        if(i%6==0) Str="7777777\n"; //0 6
        if(i==1 || i==5) Str=" 55555 \n"; //1 5
        if(1<i && i<5) Str="  333  \n"; //2 4
        if(i==3) Str="   1   \n"; //3
        printf("%s",Str);
    }
}
void ShowFunc2(void)
{
    printf("7777777\n");
    printf(" 55555\n");
    printf("  333\n");
    printf("   1\n");
    printf("  333\n");
    printf(" 55555\n");
    printf("7777777\n");
}
