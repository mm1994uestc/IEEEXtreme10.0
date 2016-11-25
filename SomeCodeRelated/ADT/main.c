#include <stdio.h>
#include <stdlib.h>
#include "mystack.h"
int main()
{
        StackType A;
        A=NewStack();
        double j=0.0;
        printf("The data we pushed into the ADT is:");
        for(j=0.0;j<=1;j+=0.2)
        {
                push(A,j);
                printf("%f\n",j);
        }
        printf("\n");
        printf("The value with index=2 is:%f\n",GetStackValue(A,2));
        j=pop(A);
        printf("The data we poped is:%f\n",j);
        printf("The Depth of the Stack is:%d\n",StackDepth(A));
        StackFree(A);
        return 0;
}
