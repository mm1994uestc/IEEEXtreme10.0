#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Array[100]={0},Temp1,i,Depth=0;
    scanf("%d %d %d",Array,Array+1,Array+2);
    a=Array[0]; b=Array[1]; b=Array[2];
    while(1)
    {
        Temp1=*Array; Temp2=*(Array+1); Temp3=*(Array+2);
        Array[100]={0};
        for(i=0;i<Temp1;i++)
        {
            Array[i]=Array[i+1]+1;
        }
        if(a==*Array && b==*(Array+1) && c==*(Array+2)) break;
        Depth++;
    }
    return 0;
}
