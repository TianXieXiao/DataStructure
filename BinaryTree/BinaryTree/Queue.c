 #pragma warning(disable:4996) 
#include "Queue.h"
#include <stdio.h>

QNode* BuyQueueNode(DataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	return node;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = BuyQueueNode(0);
}
void QueuePush(Queue* q, DataType data)
{
	assert(q);
	q->back->next = BuyQueueNode(data);
	q->back = q->back->next;
}
void QueuePop(Queue* q)
{
	QNode* delNode = NULL;
	if (QueueEmpty(q))
		return;
	delNode = q->front->next;
	q->front->next = delNode->next;
	if (NULL == delNode->next)
	{
		q->back = q->front;
	}
	free(delNode);
}
DataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->front->next->data;
}
DataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->back->data;
}
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* cur = q->front->next;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front->next;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}
	q->front = q->back = NULL;
}