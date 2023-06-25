#pragma once

typedef int DataType;
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}Node;

void SListInit(Node** head);
Node* BuySListNode(DataType data);
void SListPushBack(Node** head, DataType data);
void SListPopBack(Node** head);
void SListPushFront(Node** head, DataType data);
void SListPopFront(Node** head);
void SListInsert(Node* pos, DataType data);
void SListErase(Node* pos);
int SListSize(Node* head);
Node* SListFind(Node* head, DataType data);
void SListDestroy(Node** head);

//////////////////
void PrintSList(Node* head);
void TestSList();
