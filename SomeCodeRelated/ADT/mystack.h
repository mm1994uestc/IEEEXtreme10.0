#ifndef __mystack_h__
#define __mystack_h__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef double element;
typedef char bool;
typedef struct StackADT * StackType;
/****************************************************************************/
StackType NewStack(void);
element pop(StackType stack);
void push(StackType stack,element C);
void StackFree(StackType stack);
element GetStackValue(StackType stack,int index);
bool IsStackEmpty(StackType stack);
bool IsStackFull(StackType stack);
int StackDepth(StackType stack);
#endif
