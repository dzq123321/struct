#include"bintree.h"
int main()
{
	char *str = "ABC##DE##F##G#H##";
	char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	int n = strlen(lvr);
	BinTree bt,bt2;
	DataType key = 'D';
	BinTreeInit(&bt);
	BinTreeInit(&bt2);
	//BinTreeCreate(&bt);
	BinTreeNodeCreateBy_VLR_LVR(&bt, vlr, lvr, n);
	printf("NVLR:");
	PreoderNor(&bt);
	printf("\n");
	BinTreeNodeCreateBy_LVR_LRV(&bt,lvr, lrv,n);

	printf("NVLR:");
	PreoderNor(&bt);
	printf("\n");
	printf("NLVR:");
	InorderNor(&bt);
	printf("\n");
	printf("NLRV:");
	PostorderNor(&bt);
	printf("\n");

	//BinTreeCreateByStr(&bt, str);
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
	printf("val=%c\n", Parent(&bt, key)->data);
	Clone(&bt, &bt2);
	printf("VLR:");
	PreOrder(&bt2);
	printf("\n");
	if (Equal(&bt, &bt2))
		printf("ПаµИ\n");
	printf("-----------------------------------\n");
	printf("VLR:");
	PreoderNor(&bt);
	printf("\n");
	printf("LVR:");
	//InOrderNoR(&bt);
	printf("\n");
	printf("LRV:");
	//PostOrderNoR(&bt);
	printf("\n");

	
	return 0;
}