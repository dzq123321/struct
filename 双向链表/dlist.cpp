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
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������<-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				DListPushBack(&mydlist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������<-1����>:>");
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
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			DListInsertByVal(&mydlist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			DListDeleteByPos(&mydlist, pos);
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &key);
			DListDeleteByVal(&mydlist, key);
			break;
		case 10:
			//printf("������Ҫ���ҵ�λ��:>");
			//scanf("%d", &pos);
			////flag = SeqListFindByPos(&mylist, pos, &ret); //true false
			//if (flag)
			//	printf("���ҵ�����Ϊ:> %d\n", ret);
			//else
			//	printf("���ҵ����ݲ�����.\n");
			//break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = DListFindByVal(&mydlist, key);
			if (p == NULL)
				printf("���ҵ����ݲ�����.\n");
			else
				printf("�������ڵ��±�Ϊ:> %d\n", p->data);
			break;
			/*if (pos == -1)
				printf("���ҵ����ݲ�����.\n");
			else
				printf("�������ڵ��±�Ϊ:> %d\n", pos);
			break;*/
		case 12:
			//SCListSort(&myclist);
			break;
		case 13:
			//SCListReverse(&myclist);
			break;
		case 14:
			//printf("SeqList Length = %d\n", SCListLength(&myclist));
			break;
		case 15:

			//SCListClear(&myclist);
			break;
		case 18:
			//printf("capacity = %d\n", SeqListCapacity(&mylist));
			break;
		default:
			printf("�����������������......\n");
			break;
		}
		system("pause");
		system("cls");
	}
	//SCListDestroy(&myclist);
	return 0;
}
