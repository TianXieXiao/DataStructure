#pragma once

typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int size;        //表示栈中有多少个元素--标记栈顶
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, DataType data);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);
