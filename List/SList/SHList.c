 #pragma warning(disable:4996) 
#include "SHList.h"
#include <stdio.h>

void SHListInit(Node** head)
{
	assert(head);
	*head = BuySHListNode(0);
}
void SHListPushBack(Node* head, DataType data)
{
	assert(head);
	Node* cur = head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = BuySHListNode(data);
}
void SHListPopBack(Node* head)
{
	assert(head);
	Node* prev = NULL;
	Node* cur = NULL;
	if (NULL == head->next)
		return;
	prev = head;
	cur = head->next;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	prev->next = NULL;
}
void SHListDestroy(Node** head)
{

}
Node* BuySHListNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		assert(0);
		return;
	}
	node->next = NULL;
	node->data = data;
	return node;
}