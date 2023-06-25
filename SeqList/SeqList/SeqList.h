#pragma once

#if 0
//静态顺序表
#define MAXSIZE 100
struct SeqList
{
	int array[MAXSIZE];
	int size; //顺序表中有效元素个数
};
#endif



//动态类型的顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;//指向动态开辟的数组
	int size;      //有效数据个数
	int capacity;  //空间容量大小
}SeqList;

void SeqListInit(SeqList *psl, int capacity);
void SeqListDestroy(SeqList *psl);
void SeqListPrint(SeqList *psl);
int  SeqListSize(SeqList *psl);
int  SeqListCapacity(SeqList *psl);
int  SeqListEmpty(SeqList *psl);
void SeqListReserve(SeqList *psl, int capacity);
void SeqListPushBack(SeqList *psl, SLDataType x);
void SeqListPopBack(SeqList *psl);
void SeqListInsert(SeqList *psl, int pos, SLDataType x);
void SeqListErase(SeqList *psl, int pos);
int  SeqListFind(SeqList *psl, SLDataType x);
