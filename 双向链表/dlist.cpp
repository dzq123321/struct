#include "dlist.h"
int main()
{
	DList mydlist;
	DListInit(&mydlist);
	DListNode *p;
	int pos;
	int select = 1;
	DataType item, key;
	DataType ret;
	bool flag;
	while (select)
	{
		printf("*****************************************\n");
		printf("* [1] push_back         [2] push_front  *\n");
		printf("* [3] show_list         [0] quit_system *\n");
		printf("* [4] pop_back          [5] pop_front   *\n");
		printf("* [6] insert_pos        [7] insert_val  *\n");
		printf("* [8] delete_pos        [9] delete_val  *\n");
		printf("* [10] find_pos         [11] find_val   *\n");
		printf("* [12] sort             [13] reverse    *\n");
		printf("* [14] length           [15] clear      *\n");
		printf("* [16] modify_pos       [17] modify_val *\n");
		printf("* [18] capacity                         *\n");
		printf("*****************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				DListPushBack(&mydlist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				DListPushFront(&mydlist, item);
			}
			break;
		case 3:
			SDListShow(&mydlist);
			break;
		case 4:
			DListPopBack(&mydlist);
			break;
		case 5:
			DListPopFront(&mydlist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			DListInsertByVal(&mydlist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			DListDeleteByPos(&mydlist, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			DListDeleteByVal(&mydlist, key);
			break;
		case 10:
			//printf("请输入要查找的位置:>");
			//scanf("%d", &pos);
			////flag = SeqListFindByPos(&mylist, pos, &ret); //true false
			//if (flag)
			//	printf("查找的数据为:> %d\n", ret);
			//else
			//	printf("查找的数据不存在.\n");
			//break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DListFindByVal(&mydlist, key);
			if (p == NULL)
				printf("查找的数据不存在.\n");
			else
				printf("数据所在的下标为:> %d\n", p->data);
			break;
			/*if (pos == -1)
				printf("查找的数据不存在.\n");
			else
				printf("数据所在的下标为:> %d\n", pos);
			break;*/
		case 12:
			DListSort(&mydlist);
			break;
		case 13:
			DListReverse(&mydlist);
			break;
		case 14:
			//printf("SeqList Length = %d\n", SCListLength(&myclist));
			break;
		case 15:

			DListClear(&mydlist);
			break;
		case 17:
			printf("请输入原始的值->");
			scanf("%d", &item);
			printf("请输入变化的值->");
			scanf("%d",&ret);
			modify_val(&mydlist, item, ret);
			break;
		case 18:
			//printf("capacity = %d\n", SeqListCapacity(&mylist));
			break;
		default:
			printf("输入错误，请重新输入......\n");
			break;
		}
		system("pause");
		system("cls");
	}
	DListDestroy(&mydlist);
	return 0;
}
