#ifndef SCLIST_H_
#define SCLIST_H_
#include "common.h"
typedef struct SCListNode
{
	DataType data;
	struct SCListNode  *next;
}SCListNode;
typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t size;
}SCList;
void SCListInit(SCList *pclist);
void SCListPushBack(SCList *pclist, DataType item);
void SCListShow(SCList *pclist);
void SCListPushFront(SCList *pclist, DataType item);
bool SCListPopBack(SCList *pclist);
bool SCListPopFront(SCList *pclist);
bool SCListInsertByVal(SCList *pclist, DataType item);
bool SCListReverse(SCList *pclist);
bool SCListSort(SCList *pclist);


SCListNode * _Buynode(DataType x)
{
	SCListNode* p = (SCListNode*)malloc(sizeof(SCListNode));
	if (p == NULL)
		return NULL;
	p->next = NULL;
	p->data = x;
	return p;
}



void SCListInit(SCList *pclist)
{
	SCListNode *p = _Buynode(0);
	pclist->first = pclist->last = p;
	pclist->last->next = pclist->first;
	pclist->size = 0;
}

void SCListPushFront(SCList *pclist, DataType item)
{
	SCListNode* s = _Buynode(item);
	s->next = pclist->first->next;
	pclist->first->next = s;
	pclist->size++;
}

void SCListPushBack(SCList *pclist, DataType item)
{
	SCListNode* s = _Buynode(item);
	pclist->last->next = s;
	pclist->last = s;
	pclist->last->next = pclist->first;
	pclist->size++;
}
void SCListShow(SCList *pclist)
{
	SCListNode *p = pclist->first->next;
	while (p != pclist->first)
	{
		printf("-->%d", p->data);
		p = p->next;
	}
	printf(" over\n");
}

bool SCListPopBack(SCList *pclist)
{
	if (pclist->size == 0)
		return false;
	SCListNode *p = pclist->first;
	while (p->next != pclist->last)
	{
		p = p->next;
	}
	free(pclist->last);
	pclist->last = p;
	pclist->last->next = pclist->first;
	pclist->size--;
	return true;
}

bool SCListPopFront(SCList *pclist)
{
	if (pclist->size == 0)
		return false;
	SCListNode *p = pclist->first->next;
	pclist->first->next = p->next;
	free(p);
	pclist->size--;
	return true;
}

bool SCListInsertByVal(SCList *pclist, DataType item)
{
	SCListNode *s = _Buynode(item);
	SCListNode *p = pclist->first;
	while (p->next != pclist->first && p->next->data < s->data)
		p = p->next;
	if (p->next == pclist->first)
	{
		p->next = s;
		pclist->last = s;
		pclist->last->next = pclist->first;
		pclist->size++;
		return true;
	}
	else
	{
		s->next = p->next;
		p->next = s;
		pclist->size++;
		return true;
	}
}

bool SCListSort(SCList *pclist)
{
	if (pclist->size <2)
	{
		return false;
	}
	else
	{
		SCListNode *p1 = pclist->first->next;
		p1 = p1->next;
		SCListNode *p2=p1 ;
		SCListNode *prev;
		pclist->last = pclist->first->next;
		pclist->last->next = pclist->first;
		while (p1 != pclist->last)
		{
			prev = pclist->first;
			p2 = p2->next;
			while (prev!=pclist->last &&prev->next->data < p1->data)
				prev = prev->next;
			if (prev != pclist->last)
			{
				p1->next = prev->next;
				prev->next = p1;
			}
			else
			{
				prev->next = p1;
				pclist->last = p1;
				pclist->last->next = pclist->first;
			}
			p1 = p2;
		}
		return true;
	}
}

bool SCListReverse(SCList *pclist)
{
	if (pclist->size > 1)
	{
		SCListNode *p1 = NULL;
		SCListNode *p2 = pclist->first->next;
		SCListNode *p3 = p2->next;
		pclist->last = p2;
		while (p2 != pclist->first)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
		pclist->first->next = p1;
		pclist->last->next = pclist->first;
		return true;
	}
}
#endif