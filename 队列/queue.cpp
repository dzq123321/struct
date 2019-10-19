#include "queue.h"
int main()
{

	//SeqCQueue CQ;
	//SeqCQueueInit(&CQ, QUEUE_DEFAULT_SIZE);
	ListQueue mylistq;
	ListQueueInit(&mylistq);
	int input = 1;
	DataType item;
	while (input)
	{
		printf("*****************************************\n");
		printf("* [1] push                      [3]pop  *\n");
		printf("* [2] show              [0] quit_system *\n");
		printf("* [4] getfront             [5] getlast   *\n");
		printf("请选择:>");
		scanf("%d", &input);
		if (input == 0)
			break;
	switch (input)
			{
			case 1:
				printf("请输入要插入的数据<-1结束>:>");
				while (scanf("%d", &item), item != -1)
				{
					ListQueuePush(&mylistq, item);
					//SeqCQueuepush(&CQ, item);
				}
				break;
			case 2:
				ListQueueShow(&mylistq);
				break;
			case 3:
				ListQueuePop(&mylistq);
				break;
			case 4:
				//printf("%d \n",SeqCQueuegetfront(&CQ));
				break;
			case 5:
				//printf("%d \n", SeqCQueuegetlast(&CQ));
				break;
			default:
				printf("输入错误，请重新输入......\n");
				break;
			}
			system("pause");
			system("cls");
	}
	//SeqCQueueDestory(&CQ);
	return 0;
}

