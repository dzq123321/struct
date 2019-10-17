#include "stact.h"
int main()
{
	//Seqstact mystact;
	//StactInit(&mystact, DEFAULE_SIZE);
	ListStact myls;
	ListStactInit(&myls);
	ListStactPush(&myls, 1);
	ListStactPush(&myls, 2);
	ListStactPush(&myls, 3);
	ListStactshow(&myls);
	ListStactPop(&myls);
	ListStactshow(&myls);
	return 0;
}