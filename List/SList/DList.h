#pragma once

typedef int DataType;
typedef struct DListNode
{
	struct DListNode* next;
	struct DListNode* prev;
	DataType data;
}Node;

Node* BuyDListNode(DataType data);
void DListInit(Node** head);
void DListPushBack(Node* head, DataType data);
void DListPopBack(Node* head);
void DListPushFront(Node* head, DataType data);
void DListPopFront(Node* head);
void DListInsert(Node* pos, DataType data);
void DListErase(Node* pos);
void DListDestroy(Node** head);
///////
void TestDList();