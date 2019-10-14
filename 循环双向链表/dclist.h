#pragma once
#include "common.h"
typedef struct DCListNode
{
	DataType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;
typedef struct DCList
{
	size_t size;
	DCListNode *first;
	DCListNode *last;
};
void DCListInit(DCList *plist);
bool DCListPushBack(DCList *plist, DataType x);
void DCListShow(DCList *plist);
bool DCListPushFront(DCList *plist, DataType x);
bool DCListPopBack(DCList *plist);
bool DCListPopFront(DCList *plist);
DCListNode *DCListFindByVal(DCList *plist, DataType x);
bool DCListInsertByVal(DCList *plist, DataType x);
bool DCListDeleteByVal(DCList *plist, DataType x);
bool DCListSort(DCList *plist);
bool DCListReverse(DCList *plist);
bool DCListClear(DCList *plist);
void DCListDestroy(DCList *plist);

DCListNode * _BuyNode(DataType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	if (s == NULL)
		return NULL;
	s->data = x;
	s->next = NULL;
	s->prev = NULL;
	return s;
}

void DCListInit(DCList *plist)
{
	DCListNode *s = _BuyNode(0);
	plist->first = s;
	plist->last = s;
	plist->first->prev = plist->last;
	plist->last->next = plist->first;
	plist->size = 0;
}

bool DCListPushBack(DCList *plist, DataType x)
{
	DCListNode *s = _BuyNode(x);
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size++;
	return true;
}
void DCListShow(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over\n");
}

bool DCListPushFront(DCList *plist, DataType x)
{
	DCListNode *s = _BuyNode(x);
	s->next = plist->first->next;   //当为双循环链表的时候不用分情况，因为plist->first->next不等于null ,plist->first->next ->prev -prev ->next 
	s->next->prev = s;      //都不为null,都是指的头结点的地址。是双向的循环，只需在最后将plist->last转移到s
	plist->first->next = s;
	s->prev = plist->first;
	if (s->next == plist->first)
		plist->last = s;
	plist->size++;
	return true;
}

bool DCListPopBack(DCList *plist)
{
	if (plist->size == 0)
		return false;
	DCListNode *p = plist->last->prev;
	free(plist->last);
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size--;
	return true;
}

bool DCListPopFront(DCList *plist)
{
	if (plist->size == 0)
		return false;
	DCListNode *p = plist->first->next;
	plist->first->next = p->next;
	p->next->prev = plist->first;
	if (p->next == plist->first)
		plist->last = plist->first;
	free(p);
	plist->size--;
	return true;
}

DCListNode *DCListFindByVal(DCList *plist, DataType x)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first && p->data != x)
	{
		p = p->next;
	}
	if (p == plist->first)
		return NULL;
	return p;
}
bool DCListInsertByVal(DCList *plist, DataType x)
{
	DCListNode *s = _BuyNode(x);
	DCListNode *p = plist->first->next;
	while (p != plist->first && p->data < x)
	{
		p = p->next;
	}
	s->next = p;
	s->prev = p->prev;
	s->next->prev = s;
	s->prev->next = s;
	if (p == plist->first)
		plist->last = s;
	plist->size++;
	return true;
}

bool DCListDeleteByVal(DCList *plist, DataType x)
{
	DCListNode *p = DCListFindByVal(plist, x);
	if (p == NULL)
		return false;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	if (p == plist->last)
		plist->last = p->prev;
	free(p);
	plist->size--;
	return true;
}

bool DCListSort(DCList *plist)
{
	if (plist->size == 1)
		return true;
	DCListNode *p = plist->first->next;
	DCListNode *q = p->next;
	DCListNode *tmp = plist->first;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	p = q;
	while (p != plist->first)
	{
		q = q->next;
		tmp = plist->first;
		while (tmp->next != plist->first &&tmp->next->data < p->data)
			tmp = tmp->next;
		p->next = tmp->next;
		p->prev = tmp;
		p->next->prev = p;
		p->prev->next = p;
		if (tmp->next == plist->first)
			plist->last = p;
		p = q;
	}
	return true;
}

bool DCListReverse(DCList *plist)
{
	if (plist->size == 1)
		return true;
	DCListNode *p = plist->first->next;
	DCListNode *q = p->next;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	p = q;
	while (p != plist->first)
	{
		q = q->next;
		p->next = plist->first->next;
		p->prev = plist->first;
		p->next->prev = p;
		p->prev->next = p;
		p = q;
	}
	return true;
}

bool DCListClear(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
	plist->last = plist->first;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	return true;
}

void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}