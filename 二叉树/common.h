#ifndef _COMMOM_H_
#define _COMMOM_H_
#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define DataType char
void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif
