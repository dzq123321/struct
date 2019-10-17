#ifndef _STACT_H_
#define  _STACT_H_

#include "common.h"
#define DEFAULE_SIZE 8
#define INC_SIZE    5
//链表栈
typedef struct ListNode
{
	DataType data;
	ListNode *next;
}ListNode;
typedef ListNode*  ListStact;  
void ListStactInit(ListStact *plt);
void ListStactPush(ListStact *plt, DataType item);
void ListStactshow(ListStact *plt);
void ListStactPop(ListStact *plt);

void ListStactInit(ListStact *plt)   // plt是二级指针，是指向ListNode*指针的指针，所以在想指向（比如->data//->next）的时候,必须变为ListNode*
{
	*plt = NULL;                         //类型的指针，即（*pst）
}
void ListStactPush(ListStact *plt, DataType item)
{
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	s->next = *plt;
	s->data = item;
	*plt = s;
}

void ListStactshow(ListStact *plt)
{
	ListNode* p = *plt;
	while (p != NULL)
	{
		printf("-->%d", (p)->data);
		p = p->next;
	}
	printf("\n");
}
void ListStactPop(ListStact *plt)
{
	ListNode* p = (*plt);
	(*plt) = p->next;
	free(p);
	p = NULL;
}
//顺序栈
#if 0
typedef struct seqstact
{

	DataType *base;
	size_t capacity;
	int top;
}Seqstact;


void StactPush(Seqstact* pst, DataType data);
void StactInit(Seqstact* pst, int data);
void StactShow(Seqstact* pst);

bool _StactIsFull(Seqstact* pst)
{
	if (pst->top >= pst->capacity)
		return true;
	return false;
}
bool _StactIsEmpty(Seqstact* pst)
{
	if (pst->top == 0)
		return true;
	return false;
}
bool _StactINC(Seqstact* pst)
{
	assert(pst != NULL);
	pst->base = (DataType*)realloc(pst->base, sizeof(DataType)*(pst->capacity + INC_SIZE));
	if (pst->base == NULL)
		return false;
	printf("增容成功\n");
	pst->capacity = pst->capacity + INC_SIZE;
	return true;
}

void StactInit(Seqstact* pst, int sz)
{
	pst->capacity = sz > DEFAULE_SIZE ? sz : DEFAULE_SIZE;  //至少开辟DEFAULE_SIZE个空间
	pst->base = (DataType*)malloc(sizeof(DataType)* pst->capacity);
	pst->top = 0;
}

void StactPush(Seqstact* pst, DataType data)
{
	if (_StactIsFull(pst) && !_StactINC(pst))
	{
		printf("表以满\n");
	}
	pst->base[pst->top++] = data;
}

void StactShow(Seqstact* pst)
{
	int i = 0;
	for (; i < pst->top; i++)
	{
		printf("%d ", pst->base[i]);
	}
}


#endif

#endif