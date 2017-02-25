#include"stdafx.h"
#include"SeqList_dynamic.h"
void test()
{
	int x = 0;
	int input = 1;
	int pos = 0;
	int ret = 0;
	SeqList pSeq;
	Init_SeqList(&pSeq);
	while (input)
	{
		menu();
		printf("请选择一个操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入一个你要插入的数据:");
			scanf("%d", &x);
			Push_Back(&pSeq, x);
			break;
		case 2:
			Pop_Back(&pSeq);
			break;
		case 3:
			printf("请输入一个你要插入的数据:");
			scanf("%d", &x);
			Push_front(&pSeq, x);
			break;
		case 4:
			Pop_front(&pSeq);
			break;
		case 5:
			printf("请输入一个你要插入的数据:");
			scanf("%d", &x);
			printf("请输入你要插入的位置:");
			scanf("%d", &pos);
			Insert_SeqList(&pSeq, pos, x);
			break;
		case 6:
			printf("请输入一个你要删除的数据:");
			scanf("%d", &x);
			Remove_SeqList(&pSeq, x);
			break;
		case 7:
			printf("请输入一个你要删除的数据:");
			scanf("%d", &x);
			RemoveAll_SeqList(&pSeq, x);
			break;
		case 8:
			Bubble_Sort(&pSeq);
			break;
		case 9:
			Insertion_Sort(&pSeq);
			break;
		case 10:
			Select_Sort(&pSeq);
			break;
		case 11:
			Print_SeqList(&pSeq);
			break;
		case 12:
			printf("请输入一个你要查找的数据:");
			scanf("%d", &x);
			ret = Binary_Search(&pSeq, x);
			if (pSeq.Data[ret] == x)
			{
				printf("查找成功\n");
			}
			else
			{
				printf("查找失败\n");
			}
			break;
		case 0:
			Free_SeqList(&pSeq);
			break;
		default:
			printf("您的输入错误请重新选择\n");
			break;
		}
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}