#pragma once

typedef int DataType;
typedef int(*PCOM)(DataType left, DataType right);
typedef struct Heap
{
	DataType* array;
	int capacity;
	int size;
	PCOM pCom;  //函数指针变量---指向所有比较函数
}Heap;

int Less(DataType left, DataType right);
int Greater(DataType left, DataType right);
void HeapInit(Heap* hp, DataType* array, int size, PCOM pCom);
void HeapInsert(Heap* hp, DataType data);
void HeapErase(Heap* hp);
DataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);
void TestHeap();
void HeapSort(int array[], int size);