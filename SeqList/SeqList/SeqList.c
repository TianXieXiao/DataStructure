 #pragma warning(disable:4996) 
#include "SeqList.h"
#include <stdio.h>


void SeqListInit(SeqList *psl, int capacity)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	if (NULL == psl->array)
	{
		assert(0);
		return;
	}
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListDestroy(SeqList *psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = psl->size = 0;
	}
}
void SeqListPrint(SeqList *psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
int  SeqListSize(SeqList *psl)
{
	assert(psl);
	return psl->size;
}
int  SeqListCapacity(SeqList *psl)
{
	assert(psl);
	return psl->capacity;
}
int  SeqListEmpty(SeqList *psl)
{
	assert(psl);
	return 0 == psl->size;
}
void SeqListReserve(SeqList *psl, int capacity)
{
	assert(psl);
	if (capacity <= psl->capacity)
		return;
	psl->array = (SLDataType*)realloc(psl->array, sizeof(SLDataType)*capacity);
	assert(psl->array);
	psl->capacity *= 2;
}
void SeqListPushBack(SeqList *psl, SLDataType x)
{
	assert(psl);
	if (psl->size == psl->capacity)
		SeqListReserve(psl, SeqListCapacity(psl) * 2);
	psl->array[psl->size++] = x;
}
void SeqListPopBack(SeqList *psl)
{
	assert(psl);
	if (SeqListEmpty(psl))
		return;
	psl->size--;
}
void SeqListInsert(SeqList *psl, int pos, SLDataType x)
{
	assert(psl);
	if (pos < 0 || pos > psl->size)
	{
		printf("插入位置非法！！！\n");
		return;
	}
	if (psl->size == psl->capacity)
	{
		SeqListReserve(psl, SeqListCapacity(psl) * 2);
	}
	for (int i = psl->size; i > pos; --i)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList *psl, int pos)
{
	assert(psl);
	if (pos < 0 || pos >= psl->size)
	{
		printf("删除位置非法！！！\n");
		return;
	}
	for (int i = pos + 1; i < psl->size; ++i)
	{
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}
int  SeqListFind(SeqList *psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		if (x == psl->array[i])
			return i;
	}
	return -1;
}
