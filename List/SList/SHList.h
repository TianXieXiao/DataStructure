#pragma once

typedef int DataType;
typedef struct SHListNode
{
	struct	SHListNode* next;
	DataType data;
}Node;

void SHListInit(Node** head);
void SHListPushBack(Node* head, DataType data);
void SHListPopBack(Node* head);
void SHListDestroy(Node** head);
Node* BuySHListNode(DataType data);