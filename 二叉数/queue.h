#ifndef QUEUE_H_
#define QUEUE_H_

#include "common.h"
#include "bintree.h"
#define QueueDataType BinTreeNode*
//��ʽ����
typedef struct ListQueueNode
{
	QueueDataType data;
	struct ListQueueNode* next;
}ListQueueNode;
typedef struct ListQueue  //��ʽ������һ��ͷһ��βָ����й���
{
	ListQueueNode* front;
	ListQueueNode* tail;
}ListQueue;
void ListQueueInit(ListQueue* plq);
bool ListQueuePush(ListQueue* plq, QueueDataType x);
bool ListQueueShow(ListQueue* plq);
bool ListQueuePop(ListQueue* plq);
bool ListQueueEmpty(ListQueue* plq);
QueueDataType ListQueuetop(ListQueue* plq);

void ListQueueInit(ListQueue* plq)
{
	plq->front = plq->tail = NULL;
}
bool ListQueuePush(ListQueue* plq, QueueDataType x)
{
	ListQueueNode* s = (ListQueueNode*)malloc(sizeof(ListQueueNode));
	s->data = x;
	s->next = NULL;
	if (plq->tail == NULL)
	{
		plq->front = plq->tail = s;
		return true;
	}
	 plq->tail->next = s;
	 plq->tail = s;
	 return true;
}
bool ListQueueShow(ListQueue* plq)
{
	ListQueueNode* p = plq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return true;
}
bool ListQueuePop(ListQueue* plq)
{
	ListQueueNode* p = plq->front;
	if (p == NULL)
	{
		printf("����Ϊ��");
		return false;
	}
	else
	{
		plq->front = plq->front->next;
		free(p);
		if (plq->front == NULL)
		{
			plq->tail = NULL;
		}
		p = NULL;
		return true;
	}
}
bool ListQueueEmpty(ListQueue* plq)
{
	return plq->tail == NULL;
}

QueueDataType ListQueuetop(ListQueue* plq)
{
	return plq->front->data;
}
#endif