#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Str[100]={'0'},Res[100]={'0'};
    int Count=0;
    do{
        Str[Count]=getchar();
        Res[Count]=Str[Count];
        Count+=1;
    }while(Str[Count-1]!='\n');
    int L=Count-1,i=0,j=0;
    for(i=0;i<L;i++)
    {
        for(j=i+1;j<L;j++)
        {
            if(Str[j]==Str[i]) Str[j]='\n';
        }
    }
    for(i=0,j=0;i<L;i++)
    {
        if(Str[i]=='\n')
        {
            continue;
        }
        else
        {
            Res[j]=Str[i];
            printf("%c",Res[j]);
            j+=1;
        }
    }
    return 0;
}
