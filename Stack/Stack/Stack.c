 #pragma warning(disable:4996) 
#include "Stack.h"
#include <stdio.h>
#include <malloc.h>

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType)* 3);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->capacity = 3;
	ps->size = 0;
}
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->array = (DataType*)realloc(ps->array, sizeof(DataType)*ps->capacity * 2);
		if (NULL == ps->array)
		{
			assert(0);
			return;
		}
		ps->capacity *= 2;
	}
}
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size++] = data;
}
void StackPop(Stack* ps)
{
	asssert(ps);
	if(StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}
DataType StackTop(Stack* ps)
{
	assert(ps && !StackEmpty(ps));
	return ps->array[ps->size - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}