#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Stack_Len 10
struct StackADT{
        double ElementArray[Stack_Len];
        int Course;
};
typedef (struct StackADT*) ADT;

int main(void)
{
    ADT A;
    A->Course=10;
    printf("%d",A->Course);
    return 0;
}
