#if 1
#ifndef DLIST_H_
#define  DLIST_H_
#include  "common.h"
typedef struct DListNode
{
	DataType data;
	struct DListNode *next;
	struct DListNode *prev;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	size_t size;
};

void DListInit(DList *pdlist);
bool DListPushBack(DList *pdlist, DataType x);
void SDListShow(DList *pdlist);
bool DListPushFront(DList *pdlist, DataType x);
bool DListPopBack(DList *pdlist);
bool DListPopFront(DList *pdlist);
bool DListInsertByVal(DList *pdlist, DataType x);
bool DListDeleteByPos(DList *pdlist, size_t pos);
DListNode *DListFindByVal(DList *pdlist, DataType x);
bool DListDeleteByVal(DList *pdlist, DataType x);
bool DListReverse(DList *pdlist);
bool DListSort(DList *pdlist);
bool modify_val(DList *pdlist, DataType x,DataType y);
bool DListClear(DList *pdlist);
void DListDestroy(DList *pdlist);

DListNode *_BuyNode(DataType x)
{
	DListNode *s = (DListNode*)malloc(sizeof(DListNode));
	if (s == NULL)
		return NULL;
	s->data = x;
	s->next = NULL;
	s->prev = NULL;
}

void DListInit(DList *pdlist)
{
	DListNode *s = _BuyNode(0);
	pdlist->first = s;
	pdlist->last = s;
	pdlist->size = 0;
}

bool DListPushBack(DList *pdlist, DataType x)
{
	DListNode *s = _BuyNode(x);
	pdlist->last->next = s;
	s->prev = pdlist->last;
	pdlist->last = s;
	pdlist->size++;
	return true;
}

void SDListShow(DList *pdlist)
{
	DListNode *p = pdlist->first->next;
	while (p != NULL)
	{
		printf("-->%d", p->data);
		p = p->next;
	}
	printf("over\n");
}

bool DListPushFront(DList *pdlist, DataType x)
{
	DListNode *s = _BuyNode(x);
	if (pdlist->size == 0)
	{
		pdlist->first->next = s;
		s->prev = pdlist->first;
		pdlist->size++;
		pdlist->last = s;
		return true;
	}
	s->next = pdlist->first->next;
	s->next->prev = s;
	s->prev = pdlist->first;
	s->prev->next = s;
	pdlist->size++;
	return true;

}

bool DListPopBack(DList *pdlist)
{
	if (pdlist->size == 0)
		return false;
	DListNode *p = pdlist->last->prev;
	p->next = NULL;
	free(pdlist->last);
	pdlist->last = p;
	pdlist->size--;
	return true;
}

bool DListPopFront(DList *pdlist)
{
	DListNode *p = pdlist->first->next;
	if (pdlist->size == 0)
		return false;
	else if (pdlist->size == 1)
	{
		free(p);
		pdlist->last = pdlist->first;
		pdlist->size--;
		return true;
	}
	else
	{
		pdlist->first->next = p->next;
		p->next->prev = pdlist->first;
		free(p);
		p = NULL;
		pdlist->size--;
		return true;
	}
}

DListNode *DListFindByVal(DList *pdlist, DataType x)
{
	DListNode* p = pdlist->first->next;
	while (p != NULL &&p->data!= x)
	{
		p = p->next;
	}
	return p;
}

bool DListDeleteByPos(DList *pdlist, size_t pos)
{
	DListNode *p = pdlist->first;
	if (pdlist->size < pos)
		return false;
	while (pos--)
	{
		p = p->next;
	}
	if (p == pdlist->last)
	{
		pdlist->last = p->prev;
		pdlist->last->next = NULL;
		free(p);
		p = NULL;
		pdlist->size--;
	}
	else
	{
		p->prev->next = p->next;
		p->next = p->prev;
		free(p);
		p = NULL;
		pdlist->size--;
	}
}

bool DListDeleteByVal(DList *pdlist, DataType x)
{
	DListNode *p = NULL;
	if (pdlist->size == 0)
		return false;
	p = DListFindByVal(pdlist, x);
	if (p==NULL)
		return false;
	else if (p == pdlist->last)
	{
		pdlist->last = p->prev;
		pdlist->last->next = NULL;
		free(p);
		p = NULL;
		pdlist->size--;
	}
	else
	{
		p->prev->next = p->next;
		p->next = p->prev;
		free(p);
		p = NULL;
		pdlist->size--;
	}
}

bool DListInsertByVal(DList *pdlist, DataType x)
{
	DListNode *s = _BuyNode(x);
	DListNode *p = pdlist->first;
	if (pdlist->size == 0)
	{
		pdlist->first->next = s;
		s->prev = pdlist->first;
		pdlist->size++;
		return true;
	}
	while (p->next != NULL && p->next->data <x)
		p = p->next;
	if (p == pdlist->last)
	{
		pdlist->last->next = s;
		s->prev = pdlist->last;
		pdlist->last = s;
		pdlist->size++;
		return true;
	}
	else
	{
		s->next = p->next;
		p->next->prev = s;
		p->next = s;
		s->prev = p;
		pdlist->size++;
		return true;
	}
}

bool DListReverse(DList *pdlist)//逆序有两种方法，第一种是从第二个节点断开然后一个个头插，第二种是用三个指针p1p2p3,将原始的p1->p2变为p2->p1
{
	DListNode *p = pdlist->first->next;    //p3来记录p2的下一个位置（第二种方法当是单链表的时候还可以，当时双链表的时候改变的指针过多易出错）
	DListNode *q = p->next;
	pdlist->last = p;
	pdlist->last->next = NULL;
	p = q;
	if (pdlist->size > 1)
	{
		while (p != NULL)
		{
			q = q->next;
			p->next = pdlist->first->next;
			p->next->prev = p;
			p->prev = pdlist->first;
			p->prev->next = p;
			p= q;
		}
		return true;
	}
}


bool DListSort(DList *pdlist)
{
	DListNode *p = pdlist->first->next;
	DListNode *q = p->next;
	DListNode *front = NULL;
	pdlist->last = p;
	pdlist->last->next = NULL;
	p = q;
	if (pdlist->size > 1)
	{
		while (p != NULL)
		{
			q = q->next;
			front = pdlist->first;
			while (front->next != NULL && front->next->data < p->data)
				front = front->next;
			if (front->next == NULL)
			{
				front->next = p;
				p->prev = front;
				p->next = NULL;
				pdlist->last = p;
			}
			else
			{
				p->next = front->next;
				p->next->prev = p;
				p->prev = front;
				p->prev->next = p;
			}
			p = q;
		}
		return true;
	}
}

bool modify_val(DList *pdlist, DataType x, DataType y)
{
	DListNode *p = NULL;
	p = DListFindByVal(pdlist, x);
	if (p == NULL)
		return false;

	p->data = y;
	return true;
}
bool DListClear(DList *pdlist)
{
	DListNode *p = pdlist->first->next;
	while (p != NULL)
	{
		pdlist->first->next = p->next;
		//p->next->prev = pdlist->first;   这句话不能要，因为有可能first->next=null,所以不能null->prev ,因为你是清除不是删除，所以不用都连起来
		free(p);
		p = pdlist->first->next;
	}
	pdlist->last = pdlist->first;
	pdlist->size = 0;
	return true;
}

void DListDestroy(DList *pdlist)
{
	DListClear(pdlist);
	free(pdlist->first);
	pdlist->first = pdlist->last = NULL;
}
#endif
#endif