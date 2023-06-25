#pragma once

#if 0
//��̬˳���
#define MAXSIZE 100
struct SeqList
{
	int array[MAXSIZE];
	int size; //˳�������ЧԪ�ظ���
};
#endif



//��̬���͵�˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;//ָ��̬���ٵ�����
	int size;      //��Ч���ݸ���
	int capacity;  //�ռ�������С
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
