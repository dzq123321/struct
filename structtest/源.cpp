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
	myq->size = 100;
	myq->data = (int*)malloc(sizeof(int)*myq->size);
	myq->front = myq->tail = 0;
}
void myqueuepush(myqueue * myq, int x)
{
	myq->data[myq->tail++] = x;
}
void myqueuepop(myqueue* myq)
{
	myq->front++;
}
int myqueuefront(myqueue* myq)
{
	return myq->data[myq->front];
}
int myqueuetail(myqueue* myq)
{
	return myq->data[myq->tail - 1];
}
bool myqueueempty(myqueue* myq)
{
	return myq->front == myq->tail;
}
bool myqueuefree(myqueue* myq)
{
	free(myq->data);
	myq->data = NULL;
	return true;
}
typedef struct {
	myqueue q1;
	myqueue q2;

} MyStack;

/** Initialize your data structure here. */

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
#endif