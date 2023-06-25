 #pragma warning(disable:4996) 
#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


int Less(DataType left, DataType right)
{
	return left < right;
}
int Greater(DataType left, DataType right)
{
	return left > right;
}
void Swap(DataType* left, DataType* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void AdjustDown(Heap* hp, int parent)
{
	DataType* array = hp->array;
	int size = hp->size;

	//默认让child标记左孩子，因为parent可能不存在右孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && hp->pCom(array[child + 1], array[child]))
			child += 1;
		if (hp->pCom(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//小堆
void AdjustUp(Heap* hp)
{
	DataType* array = hp->array;
	int child = hp->size - 1;
	int parent = ((child - 1) >> 1);

	while (child)
	{
		if (hp->pCom(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		{
			return;
		}
	}
}
void HeapInit(Heap* hp, DataType* array, int size, PCOM pCom)
{
	int lastNotLeaf = 0;
	assert(hp);
	hp->array = (DataType*)malloc(sizeof(DataType)*size);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = size;
	//memcpy(hp->array,array,sizeof(DataType)*size);
	for (int i = 0; i < size; ++i)
	{
		hp->array[i] = array[i];
	}
	hp->size = size;
	hp->pCom = pCom;
	//1.找到第一个非叶子节点
	lastNotLeaf = ((size - 1) - 1) / 2;
	//2.从该节点位置开始逐个往前直到根节点，遇到一个节点应用向下调整
	for (int root = lastNotLeaf; root >= 0; --root)
	{
		AdjustDown(hp, root);
	}
}
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		hp->array = (DataType*)realloc(hp->array, sizeof(DataType)*hp->size * 2);
		if (NULL == hp->array)
		{
			assert(0);
			return;
		}
		hp->capacity *= 2;
	}
}
void HeapInsert(Heap* hp, DataType data)
{
	CheckCapacity(hp);
	//1.将元素先插入到最后一个有效元素之后
	hp->array[hp->size++] = data;
	//2.新插入元素后，可能会破坏堆的特性，因此需要对堆进行调整
	AdjustUp(hp);
}
void HeapErase(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	//1.将堆顶元素与堆中最后一个元素交换
	Swap(&hp->array[hp->size - 1], &hp->array[0]);

	//2.将堆中有效元素个数-1
	hp->size -= 1;
	//3.将堆顶元素向下调整
	AdjustDown(hp, 0);
}
//获取堆顶元素
DataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array = NULL;
		hp->capacity = 0;
		hp->size = 0;
	}
}
void TestHeap()
{
	int array[] = {6,7,8,3,5,1};
	Heap hp;

	HeapInit(&hp, array, sizeof(array) / sizeof(array[0]), Greater);

	printf("top = %d\n", HeapTop(&hp));
	printf("size = %d\n", HeapSize(&hp));

	HeapInsert(&hp, 0);
	printf("top = %d\n", HeapTop(&hp));
	printf("size = %d\n", HeapSize(&hp));

	HeapErase(&hp);
	printf("top = %d\n", HeapTop(&hp));
	printf("size = %d\n", HeapSize(&hp));

	HeapDestroy(&hp);
}

void HeapAdjust(int array[], int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int array[], int size)
{
	int end = size - 1;
	//1.建堆  升序--->大堆 降序--->小堆
	for (int root = ((size - 2) >> 1); root >= 0; --root)
	{
		HeapAdjust(array, size, root);
	}

	//2.利用堆删除的思想来进行排序
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		--end;
	}
}