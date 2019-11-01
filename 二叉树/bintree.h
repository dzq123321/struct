#ifndef BINTREE_H_
#define BINTREE_H_
#include"common.h"

//ABC##DE##F##G#H##

typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;

void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
void BinTreeCreateByStr(BinTree *t, char *str);
BinTreeNode* _BinTreeCreate_2();
void BinTreeCreate(BinTree *t);
BinTreeNode* _BinTreeCreateByStr (BinTreeNode* t);
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
size_t _num (BinTreeNode* t);
size_t num(BinTree *t);
size_t _Height (BinTreeNode* t);
size_t Height(BinTree *t);
void _LevleOrder(BinTreeNode *t);
void LevleOrder(BinTree *t);

BinTreeNode* _Find(BinTreeNode* t,DataType key);
BinTreeNode* Find(BinTree* t,DataType key);
BinTreeNode* _Parent(BinTreeNode *t, DataType key);
BinTreeNode* Parent(BinTree *t, DataType key);
BinTreeNode* _Clone(BinTreeNode *t);
void Clone(BinTree *t1, BinTree *t2);
bool _Equal(BinTreeNode *t1, BinTreeNode *t2);// true false

bool Equal(BinTree *t1, BinTree *t2);// true false

void _PreoderNor(BinTreeNode *t);
void PreoderNor(BinTree *t);

void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}

void BinTreeCreate(BinTree *t)
{
	//_BinTreeCreate(&t->root);
	t->root = _BinTreeCreate_2();
}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if(item == '#')
	{
		*t = NULL;
	}	
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate_1(&((*t)->leftChild));
		_BinTreeCreate_1(&((*t)->rightChild));
	}
}
BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
	scanf("%c", &item);
	if(item == '#')
	{
		return NULL;
	}
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = _BinTreeCreate_2();
		t->rightChild = _BinTreeCreate_2();
		return t;
	}
}

BinTreeNode* _BinTreeCreateByStr (char* str)  //递归需要变换参数时可以用static或者全局变量
{
	static int i =0;
	BinTreeNode *t;
	if( str[i] == '\0' || str[i] == '#' )
		return NULL;
	else
	{
		t=(BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[i];
		i++;
		t->leftChild = _BinTreeCreateByStr (str);
		i++;
		t->rightChild = _BinTreeCreateByStr (str);
		return t;
	}
}

void BinTreeCreateByStr(BinTree *t, char *str)
{
	t->root = _BinTreeCreateByStr(str);
}

void _PreOrder(BinTreeNode *t)//二叉树的四种遍历，前序 中序 后序 按层遍历
{
	if(t != NULL )
	{
		printf("%c ", t->data);
		_PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
	}
}
void PreOrder(BinTree *t)
{
	_PreOrder(t->root);
}

void _InOrder(BinTreeNode *t)
{
		if(t != NULL )
	{
		_PreOrder(t->leftChild);
		printf("%c ", t->data);		
		_PreOrder(t->rightChild);
	}
}
void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _PostOrder(BinTreeNode *t)
{
		if(t != NULL )
	{
        _PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
		printf("%c ", t->data);				
	}
}
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}

#include "queue.h"

void LevleOrder(BinTree *t)
{
	_LevleOrder(t ->root);
}
void _LevleOrder(BinTreeNode *t)//借助一个队列，先将一个根节点入队，出队，再入左右两个节点，出对(左节点)，直到对为空
{
	ListQueue mylistq;
	ListQueueInit(&mylistq);
	ListQueuePush(&mylistq,t);
	while(!(ListQueueEmpty(&mylistq)))
	{
		t = ListQueuetop(&mylistq);
		ListQueuePop(&mylistq);
		printf("%c ",t->data);
		if(t->leftChild != NULL)
			ListQueuePush(&mylistq,t->leftChild);
		if(t->rightChild != NULL)
			ListQueuePush(&mylistq,t->rightChild );
	}
}

size_t _Height (BinTreeNode* t)
{
	if (t ==NULL)
		return 0;
	else
	{
		return _Height (t->leftChild)>_Height ( t->rightChild )?_Height (t->leftChild)+1:_Height (t->rightChild)+1 ;
	}
}
size_t Height(BinTree *t)
{
	return _Height (t->root);
}

size_t _num (BinTreeNode* t)
{
	if (t ==NULL)
		return 0;
	else
	{
		return _num (t->leftChild)+_num ( t->rightChild )+1;
	}
}
size_t num(BinTree *t)
{
	return  _num ( t->root);
}

BinTreeNode* _Find(BinTreeNode* t,DataType key)
{
	BinTreeNode* p;
	if(t == NULL)
		return NULL;
	if(t->data == key)
		return t;
	p=_Find(t->leftChild, key);
	if(p != NULL)
		return p;
	return _Find(t->rightChild, key);
}
BinTreeNode* Find(BinTree* t,DataType key)
{
	BinTreeNode* pos = _Find(t->root ,key);
	return pos;
}

BinTreeNode* _Parent(BinTreeNode *t, DataType key)
{
	BinTreeNode* pr;
	BinTreeNode* p = _Find(t, key);
	if (p == NULL || t == NULL || p == t)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	pr = _Parent(t->leftChild, key);
	if (pr != NULL)
		return pr;
	return _Parent(t->rightChild, key);

}
BinTreeNode* Parent(BinTree *t, DataType key)
{
	return  _Parent(t->root, key);
}

BinTreeNode* _Clone(BinTreeNode *t)
{
	if (t == NULL)
		return NULL;
	BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	p->data = t->data;
	p->leftChild = _Clone(t->leftChild);
	p->rightChild = _Clone(t->rightChild);
	return p;

}
void Clone(BinTree *t1, BinTree *t2)
{
	t2->root = _Clone(t1->root);
}
bool _Equal(BinTreeNode *t1, BinTreeNode *t2)// true false
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return (t1->data == t2->data) && _Equal(t1->leftChild, t2->leftChild)
		&& _Equal(t1->rightChild, t2->rightChild);
}

bool Equal(BinTree *t1, BinTree *t2)// true false
{
	return _Equal(t1->root, t2->root);
}

#include "stact.h"
void _PreoderNor(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode* q;
		ListStact mystact;
		ListStactInit(&mystact);
		ListStactPush(&mystact, t);
		while (!(ListStactEmpty(&mystact)))
		{
			q = ListStactTop(&mystact); 
			ListStactPop(&mystact);
			printf("%c ", q->data);
			if(q->rightChild != NULL)
				ListStactPush(&mystact, q->rightChild);
			if (q->leftChild != NULL)
				ListStactPush(&mystact, q->leftChild);
		}
	}
}
void PreoderNor(BinTree *t)
{
	_PreoderNor(t->root);
}


void _InOrderNoR(BinTreeNode *t);
void InOrderNoR(BinTree *t);
//void _PostOrderNoR(BinTreeNode *t);
//void PostOrderNoR(BinTree *t);
void _InOrderNoR(BinTreeNode *t)
{
	if (t != NULL)
	{
		if (t->leftChild != NULL)
		{
			_PreoderNor(t->leftChild);
		}
		printf("%c ", t->data);
		if (t->rightChild != NULL)
		{
			_PreoderNor(t->rightChild);
		}
	}

}
void InOrderNoR(BinTree *t)
{
	_InOrderNoR(t->root);
}


void _PostOrderNoR(BinTreeNode *t)
{
	if (t != NULL)
	{
		if (t->leftChild != NULL)
		{
			_PreoderNor(t->leftChild);
		}
		if (t->rightChild != NULL)
		{
			_PreoderNor(t->rightChild);
		}
		printf("%c ", t->data);
	}
}
void PostOrderNoR(BinTree *t)
{
	_PostOrderNoR(t->root);
}
#endif
