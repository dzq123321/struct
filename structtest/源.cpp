#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*//括号匹配问题   (()  ->false  ([{}])->true 
bool test(char* p,int n)
{
	if (p == NULL)
		return false;
	int i = 0;
	char* right = (char*)malloc(sizeof(char)*n);
	while (*p != '\0')
	{
		if (*p == '{' || *p == '[' || *p == '(')
			right[i++] = *p;
		else
		{                                          //i == 0 第一个是右括号 }]),直接返回false
			if (i == 0 ||* p == '}' && right[--i] != '{'
				|| *p == ']' && right[--i] != '['
				|| *p == ')' && right[--i] != '(')//不能直接*p == ']' && right[--i] == '['就返回true ,因为有可能是（）（ 这种形式，直接返回true就不能检测后面的内容
				return false;                  //    所以只能检测错误不能检测正确
		}
		p++;
	}
	if (i == 0)
		return true;
	return false;
}
int main()
{
	printf("请输入字符串\n");
	char s[20] = { 0 };
	scanf("%s", s);
	int len = strlen(s);
	bool b = 0;
	b=test(s,len);
	printf("%d\n", b);
	return 0;
}*/
#if 0
typedef struct myqueue
{
    int *data;
    size_t size;
    int front;
    int tail;
} myqueue;
void myqueueInit(myqueue *myq)
{
    myq ->size = 100;
    myq->data = (int*)malloc(sizeof(int)*myq->size);
    myq->front = myq->tail =0;
}
void myqueuepush (myqueue * myq,int x)
{
   myq->data[myq->tail++]= x;
}
void myqueuepop (myqueue* myq)
{
    myq->front ++;
}
int myqueuefront(myqueue* myq)
{
    return myq->data[myq->front];
}
int myqueuetail(myqueue* myq)
{
        return myq->data[myq->tail-1];
}
bool myqueueempty(myqueue* myq)
{
    return myq->front == myq->tail;
}
bool myqueuefree (myqueue* myq)
{
    free(myq->data);
    myq->data =NULL;
    return true;
}
typedef struct {
    myqueue q1;
    myqueue q2;
    
} MyStack;


/* Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* mys = (MyStack*)malloc(sizeof(MyStack));
	myqueueInit(&(mys->q1));
	myqueueInit(&(mys->q2));
	return mys;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	myqueue *pnoemptyque;
	myqueue *pemptyque;
	if (myqueueempty(&(obj->q1)))
	{
		pemptyque = &(obj->q1);
		pnoemptyque = &(obj->q2);
	}
	else
	{
		pemptyque = &(obj->q2);
		pnoemptyque = &(obj->q1);
	}
	myqueuepush(pnoemptyque, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int val;
	myqueue *pnoemptyque;
	myqueue *pemptyque;
	if (myqueueempty(&(obj->q1)))
	{
		pemptyque = &(obj->q1);
		pnoemptyque = &(obj->q2);
	}
	else
	{
		pemptyque = &(obj->q2);
		pnoemptyque = &(obj->q1);
	}
	while (!myqueueempty(pnoemptyque))
	{
		val = myqueuefront(pnoemptyque);
		myqueuepop(pnoemptyque);
		if (myqueueempty(pnoemptyque))
			break;
		myqueuepush(pemptyque, val);
	}
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	myqueue *pnoemptyque;
	myqueue *pemptyque;
	if (myqueueempty(&(obj->q1)))
	{
		pemptyque = &(obj->q1);
		pnoemptyque = &(obj->q2);
	}
	else
	{
		pemptyque = &(obj->q2);
		pnoemptyque = &(obj->q1);
	}
	return   myqueuetail(pnoemptyque);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (myqueueempty(&(obj->q1)) && myqueueempty(&(obj->q2)))
		return true;
	else
		return false;

}

void myStackFree(MyStack* obj) {
	myqueuefree(&(obj->q1));
	myqueuefree(&(obj->q2));
	free(obj);
	obj = NULL;
}
#endif
#if 0  //设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈https://leetcode-cn.com/problems/min-stack/
typedef struct stact
{
    int *base;
    int capacity;
    int top;
}stact;
bool StactIsFull (stact *pst)
{
    return pst->top >= pst-> capacity;
}
bool StactIsEmpty (stact *pst)
{
    return pst -> top == 0;
}
stact * StactCreat()
{
    stact *pst =(stact*) malloc(sizeof(stact));
    if(pst == NULL)
        return NULL;
    pst ->capacity = 100;
    pst ->base = (int*)malloc(sizeof(int)*pst->capacity);
    pst -> top = 0;
    return pst;
}
void StactPush (stact *pst,int data)
{
    if(StactIsFull (pst))
        return;
    pst-> base[pst->top++]=data;
}
void StactPop (stact *pst)
{
    if(StactIsEmpty(pst))
        return ;
    pst->top--;
}
int Stacttop(stact *pst)
{
    assert(pst->top !=0);
    return pst->base[pst->top-1];
}

typedef struct {
    stact *mystact;
    stact *minstact;
    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *mins =(MinStack*)malloc(sizeof(MinStack));
    mins ->mystact=StactCreat();
    mins ->minstact=StactCreat();
    return mins;
}

void minStackPush(MinStack* obj, int x) {
    StactPush(obj->mystact,x);
    if(StactIsEmpty(obj->minstact) || x<=Stacttop(obj->mystact))
        StactPush(obj->minstact,x);
}

void minStackPop(MinStack* obj) {
    int val =Stacttop(obj->mystact);
    StactPop (obj->mystact);
    if(val == Stacttop(obj->minstact))
    {
        StactPop(obj->minstact);
    }
  
}

int minStackTop(MinStack* obj) {
  return Stacttop(obj->mystact);
}

int minStackGetMin(MinStack* obj) {
    
  return Stacttop(obj->minstact);
}

void minStackFree(MinStack* obj) {
    obj->mystact ->top= obj->mystact ->capacity=obj->minstact ->top=obj->minstact ->capacity=0;
    free(obj -> mystact);
    free(obj -> minstact);
    free(obj);
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
#endif
//用栈实现队列 思路：用两个栈来实现 https://leetcode-cn.com/problems/implement-queue-using-stacks/
#if 0
typedef struct seqstact
{
	int *base;
	size_t capacity;
	int top;
}Seqstact;
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

void SeqStactInit(Seqstact* pst )
{
	pst->capacity = 100;
	pst->base = (int*)malloc(sizeof(int)* pst->capacity);
	pst->top = 0;
}

void SeqStactPush(Seqstact* pst, int data)
{
	if (_StactIsFull(pst))
	{
		printf("表以满\n");
	}
	pst->base[pst->top++] = data;
}
void SeqStactPop(Seqstact* pst)
{
	if (_StactIsEmpty(pst) )
	{
		printf("表为空\n");
		return;
	}
	pst->top--;
}
int SeqStacttop (Seqstact* pst)
{
    return pst ->base[pst -> top--];
}
bool SeqStactfree (Seqstact* pst)
{
    free(pst ->base);
        pst->base =NULL;
    return true;
}
typedef struct myqueue
{
    Seqstact s1;
    Seqstact s2;
}MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
      MyQueue *pmq = (MyQueue*)malloc(sizeof(MyQueue));
        SeqStactInit(&( pmq ->s1));
       SeqStactInit(&( pmq ->s2));  
        return pmq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    Seqstact *pempty ;
        Seqstact*pnoempty;
        if(_StactIsFull(&( obj ->s1)  )) 
        {
         pempty =  &(obj ->s1) ;
            pnoempty =  &(obj ->s2) ;
            
        }
        else
        {
            pempty =  &(obj ->s2) ;
            pnoempty =  &(obj ->s1) ; 
        }
     SeqStactPush(pnoempty, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
     Seqstact *pempty ;
        Seqstact*pnoempty;
    int val;
        if(_StactIsFull(&( obj ->s1)  )) 
        {
         pempty =  &(obj ->s1) ;
            pnoempty =  &(obj ->s2) ;
            
        }
        else
        {
            pempty =  &(obj ->s2) ;
            pnoempty =  &(obj ->s1) ; 
        }
      while(!_StactIsEmpty(pnoempty))
      {
          val =SeqStacttop (pnoempty);
          SeqStactPop(pnoempty);
          if(!_StactIsEmpty(pnoempty))
          SeqStactPush(pempty,val);
      }
          while(!_StactIsEmpty(pempty))
      {
          val =SeqStacttop (pempty);
          SeqStactPop(pempty);
          SeqStactPush(pnoempty,val);
      }
  return 1;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    
  Seqstact *pempty ;
        Seqstact*pnoempty;
    int val,t;
        if(_StactIsFull(&( obj ->s1)  )) 
        {
         pempty =  &(obj ->s1) ;
            pnoempty =  &(obj ->s2) ;
            
        }
        else
        {
            pempty =  &(obj ->s2) ;
            pnoempty =  &(obj ->s1) ; 
        }
      while(!_StactIsEmpty(pnoempty))
      {
          val =SeqStacttop (pnoempty);
          SeqStactPop(pnoempty);
          SeqStactPush(pempty,val);
      }
    t = val;
         while(!_StactIsEmpty(pempty))
      {
          val =SeqStacttop (pempty);
          SeqStactPop(pempty);
          SeqStactPush(pnoempty,val);
      }
    return 1;
    
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(_StactIsFull(&( obj ->s1))&&_StactIsFull(&( obj ->s2)) )
        return false;
    return true;;
  
}

void myQueueFree(MyQueue* obj) {
    SeqStactfree((&( obj ->s1)));
           SeqStactfree((&( obj ->s2)));          
    free(obj);
    obj =NULL;
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
#endif
