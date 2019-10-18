#include "stact.h"
int main()
{
	Seqstact mystact;
	SeqStactInit(&mystact, DEFAULE_SIZE);
	//Seqstact* mystact=Seqstactcreat(DEFAULE_SIZE);
	SeqStactPush(&mystact, 5);
	SeqStactPush(&mystact, 3);
	SeqStactPush(&mystact, 2);
	SeqStactShow(&mystact);
	SeqStactPop(&mystact);
	SeqStactShow(&mystact);
	/*ListStact myls;
	ListStactInit(&myls);
	ListStactPush(&myls, 1);
	ListStactPush(&myls, 2);
	ListStactPush(&myls, 3);
	ListStactshow(&myls);
	ListStactPop(&myls);
	ListStactshow(&myls);
	ListStactempty(&myls);
	printf("====================\n");
	ListStactshow(&myls);*/
	
	return 0;
}