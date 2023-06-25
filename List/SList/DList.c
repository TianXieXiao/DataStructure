 #pragma warning(disable:4996) 
#include "DList.h"
#include <stdio.h>

Node* BuyDListNode(DataType data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (NULL == newNode)
	{
		assert(0);
		return;
	}
	newNode->next = newNode->prev = NULL;
	newNode->data = data;
	return newNode;
}
void DListInit(Node** head)
{
	assert(head);
	*head = BuyDListNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}
void DListPushBack(Node* head, DataType data)
{
	DListInsert(head, data);
}
void DListPopBack(Node* head)
{
	assert(head);
	DListErase(head->prev);
}
void DListPushFront(Node* head, DataType data)
{
	DListInsert(head->next, data);
}
void DListPopFront(Node* head)
{
	assert(head);
	DListErase(head->next);
}
void DListInsert(Node* pos, DataType data)
{
	Node* newNode = NULL;
	if (NULL == pos)
	{
		return;
	}
	newNode = BuyDListNode(data);
	newNode->prev = pos->prev;
	newNode->next = pos;
	newNode->prev->next = newNode;
	pos->prev = newNode;
}
void DListErase(Node* pos)
{
	if (NULL == pos)
	{
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
void DListDestroy(Node** head)
{
	assert(head);
	Node* cur = (*head)->next;
	while (cur)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	free(*head);
	*head = NULL;
}
///////
void PrintDList(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}