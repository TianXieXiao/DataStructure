 #pragma warning(disable:4996) 
#include "SList.h"
#include <stdio.h>


void SListInit(Node** head)
{
	assert(head);
	*head = NULL;
}
Node* BuySListNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		assert(0);
		return;
	}
	node->data = data;
	node->next = NULL;
	return node;
}
void SListPushBack(Node** head, DataType data)
{
	assert(head);
	if (NULL == *head)
	{
		*head = BuySListNode(data);
	}
	else
	{
		Node* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = BuySListNode(data);
	}
}
void SListPopBack(Node** head)
{
	assert(head);
	if (NULL == *head)
		return;
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		Node* cur = *head;
		Node* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next = NULL;
	}
}
void SListPushFront(Node** head, DataType data)
{
	assert(head);
	Node* newNode = BuySListNode(data);
	newNode->next = *head;
	*head = newNode;
}
void SListPopFront(Node** head)
{
	assert(head);
	if (NULL == *head)
		return;
	Node* delNode = *head;
	*head = delNode->next;
	free(delNode);
}
void SListInsert(Node* pos, DataType data)
{
	Node* newNode = NULL;
	if (NULL == pos)
	{
		return;
	}
	newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListErase(Node* pos)
{
	Node* delNode;
	if (NULL == pos || NULL == pos->next)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}
int SListSize(Node* head)
{
	int count = 0;
	Node* cur = head;
	while (cur)
	{
		cur = cur->next;
		++count;
	}
	return count;
}
Node* SListFind(Node* head, DataType data)
{
	Node* cur = head;
	while (cur)
	{
		if (data == cur->data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void SListDestroy(Node** head)
{
	Node* delNode = NULL;
	assert(head);
	while (NULL != *head)
	{
		delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}

//////////////////
void PrintSList(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void TestSList();