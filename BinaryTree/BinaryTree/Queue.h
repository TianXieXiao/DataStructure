#pragma once

typedef int DataType;
typedef struct QNode
{
	struct QNode* next;
	DataType data;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* back;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);