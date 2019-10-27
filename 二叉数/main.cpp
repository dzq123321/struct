#include"bintree.h"
int main()
{
	char *str = "ABC##DE##F##G#H##";
	BinTree bt;
	DataType key = 'D';
	BinTreeInit(&bt);
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str);
	printf("VLR:");
	PreOrder(&bt);
	printf("\n");
	printf("LVR:");
	InOrder(&bt);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt);
	printf("\n");
	printf("Levle:");
	LevleOrder(&bt);
	printf("\n");
	printf("height = %d\n",Height(&bt));
	printf("num= %d\n",num(&bt));
	printf("val=%c\n",Find(&bt,key)->data);
	return 0;

}