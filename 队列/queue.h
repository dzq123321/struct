#ifndef QUEUE_H_
#define QUEUE_H_

#include "common.h"

#define QUEUE_DEFAULT_SIZE 8
//��ʽ����
typedef struct ListQueueNode
{
	DataType data;
	struct ListQueueNode* next;
}ListQueueNode;
typedef struct ListQueue  //��ʽ������һ��ͷһ��βָ����й���
{
	ListQueueNode* front;
	ListQueueNode* tail;
}ListQueue;
void ListQueueInit(ListQueue* plq);
bool ListQueuePush(ListQueue* plq, DataType x);
bool ListQueueShow(ListQueue* plq);
bool ListQueuePop(ListQueue* plq);


void ListQueueInit(ListQueue* plq)
{
	plq->front = plq->tail = NULL;
}
bool ListQueuePush(ListQueue* plq, DataType x)
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

#if 0
//ѭ��˳�����
typedef struct SeqCQueue
{
	DataType *base;
	size_t capacity;
	int front;
	int tail;
}SeqCQueue;

bool SeqCQueueInit(SeqCQueue *pcq, int sz);
bool SeqCQueuepush(SeqCQueue *pcq, DataType x);
bool SeqCQueueShow(SeqCQueue *pcq);
bool SeqCQueuePop(SeqCQueue *pcq);
bool SeqCQueueDestory(SeqCQueue *pcq);
bool SeqCQueueDestory(SeqCQueue *CQ);
DataType SeqCQueuegetfront(SeqCQueue *pcq);  //�õ�ѭ�����е�һ��Ԫ��
DataType SeqCQueuegetlast(SeqCQueue *pcq);//�õ�ѭ����������Ԫ��
bool SeqCQueueIsFull(SeqCQueue *pcq)
{
	return (pcq->tail + 1) % pcq->capacity == pcq->front;  //��һ���ǿյĿռ䣬�����Ƚ��Ƿ�����
}
bool SeqCQueueIEmpty(SeqCQueue *pcq)
{
	return pcq->tail == pcq->front;
}


bool SeqCQueueInit(SeqCQueue *pcq, int sz)
{
	pcq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	pcq->capacity++;
	pcq->base = (DataType*)malloc(sizeof(DataType)* (pcq->capacity + 1));
	if (pcq->base == NULL)
		return false;
	pcq->front = pcq->tail = 0;
	return true;
}
bool SeqCQueuepush(SeqCQueue *pcq, DataType x)
{
	if (SeqCQueueIsFull(pcq))
	{
		printf("��������\n");
		return false;
	}
	pcq->base[pcq->tail] = x;
	pcq->tail = (pcq->tail + 1) % pcq->capacity;
	return true;
}

bool SeqCQueueShow(SeqCQueue *pcq)
{
	for (int i = pcq->front; i != pcq->tail;)
	{
		printf("%d ", pcq->base[i]);
		i = (i + 1) % pcq->capacity;
	}

	printf("\n");
	return true;
}

bool SeqCQueuePop(SeqCQueue *pcq)
{
	if (SeqCQueueIEmpty(pcq))
	{
		printf("����Ϊ��\n");
		return false;
	}
	pcq->front = (pcq->front + 1) % pcq->capacity;
	return true;
}

bool SeqCQueueDestory(SeqCQueue *pcq)
{
	free(pcq->base);
	pcq->capacity = pcq->front = pcq->tail = 0;
	return true;
}

DataType SeqCQueuegetfront(SeqCQueue *pcq)
{
	return pcq->base[pcq->front];
}
DataType SeqCQueuegetlast(SeqCQueue *pcq)
{
	return pcq->base[(pcq->tail - 1 + pcq->capacity) % pcq->capacity]; //��ֹ��tailΪ0��ʱ�� 0-1=-1,�ᷢ������Խ��
}
#endif



#endif

/**/