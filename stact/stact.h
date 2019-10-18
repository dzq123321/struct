#ifndef _STACT_H_
#define  _STACT_H_

#include "common.h"
#define DEFAULE_SIZE 8
#define INC_SIZE    5
//����ջ
typedef struct ListNode
{
	DataType data;
	ListNode *next;
}ListNode;
#if 0
typedef ListNode*  ListStact;  
void ListStactInit(ListStact *plt);
void ListStactPush(ListStact *plt, DataType item);
void ListStactshow(ListStact *plt);
void ListStactPop(ListStact *plt);
void ListStactempty(ListStact *plt);

void ListStactInit(ListStact *plt)   // plt�Ƕ���ָ�룬��ָ��ListNode*ָ���ָ�룬��������ָ�򣨱���->data//->next����ʱ��,�����ΪListNode*
{
	*plt = NULL;                         //���͵�ָ�룬����*pst��
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

void ListStactempty(ListStact *plt)
{
	ListNode* p = (*plt);
	while (p != NULL)
	{
		(*plt) = p->next;
		free(p);
		p = (*plt);
	}
}
#endif
//˳��ջ
#if 1
typedef struct seqstact
{

	DataType *base;
	size_t capacity;
	int top;
}Seqstact;


void SeqStactPush(Seqstact* pst, DataType data);
void SeqStactInit(Seqstact* pst, int data);
void SeqStactShow(Seqstact* pst);
seqstact* Seqstactcreat(int x);
void SeqStactPop(Seqstact* pst);

seqstact* Seqstactcreat(int x)
{
	seqstact* mystact = (seqstact*)malloc(sizeof(seqstact));
	if (mystact == NULL)
		return NULL;
	mystact->capacity = x > DEFAULE_SIZE ? x : DEFAULE_SIZE;
	mystact->base = (DataType*)malloc(sizeof(DataType)*mystact->capacity);
	mystact->top = 0;
	return mystact;
}
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
	printf("���ݳɹ�\n");
	pst->capacity = pst->capacity + INC_SIZE;
	return true;
}

void SeqStactInit(Seqstact* pst, int sz)
{
	pst->capacity = sz > DEFAULE_SIZE ? sz : DEFAULE_SIZE;  //���ٿ���DEFAULE_SIZE���ռ�
	pst->base = (DataType*)malloc(sizeof(DataType)* pst->capacity);
	pst->top = 0;
}

void SeqStactPush(Seqstact* pst, DataType data)
{
	if (_StactIsFull(pst) && !_StactINC(pst))
	{
		printf("������\n");
	}
	pst->base[pst->top++] = data;
}

void SeqStactShow(Seqstact* pst)
{
	int i = pst->top-1;
	for (; i >=0; i--)
	{
		printf("%d-- ", pst->base[i]);
	}
	printf("\n");
}

void SeqStactPop(Seqstact* pst)
{
	if (_StactIsEmpty(pst) )
	{
		printf("��Ϊ��\n");
		return;
	}
	pst->top--;
}
#endif

#endif