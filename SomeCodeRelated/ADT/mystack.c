#include "mystack.h"
#define Stack_Len 100
#define true 1
#define false 0
struct StackADT{
        element ElementArray[Stack_Len];
        int Course;
};
void Error(char *Str)
{
	int L=0;
	for(L=0;L<strlen(Str);L++)
	{
		printf("%c",*(Str+L));
	}
	while(1);
}
StackType NewStack(void)
{
	StackType stack;
	stack=(StackType)malloc(sizeof(StackType)*1);
	stack->Course=0;
	return stack;
}
element pop(StackType stack)
{
	if(stack->Course == 0) Error("The Stack is empty!No element return!");
	return stack->ElementArray[--stack->Course];
}
void push(StackType stack,element C)
{
	if(stack->Course >= Stack_Len) Error("The Stack is Fulled!No more elements can be inserted!");
	stack->ElementArray[stack->Course++]=C;
}
void StackFree(StackType stack)
{
	free(stack);
}
element GetStackValue(StackType stack,int index)
{
	if(index < 0 || index >= stack->Course) Error("Wrong index enter!");
	return stack->ElementArray[index];
}
bool IsStackEmpty(StackType stack)
{
	if(stack->Course==0) return true;
	else return false;
}
bool IsStackFull(StackType stack)
{
	if(stack->Course==Stack_Len) return true;
	else return false;
}
int StackDepth(StackType stack)
{
	return stack->Course;
}
