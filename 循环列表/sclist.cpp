#include "sclist.h"
int main()
{
	SCList myclist;
	SCListInit(&myclist);
	SCListNode *p;
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
				SCListPushBack(&myclist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushFront(&myclist, item);
			}
			break;
		case 3:
			SCListShow(&myclist);
			break;
		case 4:
			SCListPopBack(&myclist);
			break;
		case 5:
			SCListPopFront(&myclist);
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
			SCListInsertByVal(&myclist,item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			//SListDeleteByVal(&mylist, key);
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
			pos = SCListFindByVal(&myclist, key);
			if (pos == -1)
				printf("查找的数据不存在.\n");
			else
				printf("数据所在的下标为:> %d\n", pos);
			break;
		case 12:
			SCListSort(&myclist);
			break;
		case 13:
			SCListReverse(&myclist);
			break;
		case 14:
			printf("SeqList Length = %d\n", SCListLength(&myclist));
			break;
		case 15:

			SCListClear(&myclist);
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
	SCListDestroy(&myclist);
	return 0;
}
