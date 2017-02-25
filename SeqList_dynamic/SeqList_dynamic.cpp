// SeqList_dynamic.cpp : 定义控制台应用程序的入口点。
#include"stdafx.h"
#include"SeqList_dynamic.h"
void menu()
{
	printf("***********0.exit****1.Push_Back****2.Pop_Back************\n");
	printf("***********3.Push_front*************4.Pop_front************\n");
	printf("***********5.Insert_SeqList**********6.Remove_SeqList*****\n");
	printf("***********7.RemoveAll_SeqList*****8.Bubble_Sort*********\n");
	printf("***********9.Insertion_Sort*********10.Select_Sort**********\n");
	printf("**********11.Print_SeqList**********12.Binary_Search*******\n");
}
void  Print_SeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i<pSeq->size; i++)
	{
		printf("%d ", pSeq->Data[i]);
	}
	printf("\n");
}
void Init_SeqList(pSeqList pSeq)
{
	pSeq->Data = (DataType*)malloc(sizeof(DataType)*MAX_INIT);
	if (NULL == pSeq->Data)//防止赋值出错
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	pSeq->size = 0;
	pSeq->capacity = MAX_INIT;
}
void Judge_Full(pSeqList pSeq)
{
	if (pSeq->capacity == pSeq->size)
	{
		DataType *tmp = (DataType*)realloc(pSeq->Data, (pSeq->capacity + MAX_ADD)*sizeof(DataType));
		//给指定指针，重新分配空间大小，如果失败则返回空指针NULL
		if (NULL == pSeq->Data)
		{
			printf("out of memory\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			pSeq->Data = tmp;
			pSeq->capacity += MAX_ADD;
		}
	}
}
void Push_Back(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	Judge_Full(pSeq);
	pSeq->Data[pSeq->size] = x;
	pSeq->size++;
}
void Pop_Back(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("顺序表已空\n");
		return;
	}
	pSeq->size--;
}
void Push_front(pSeqList pSeq, DataType x)   
{
	//在顺序表的前面添加元素   
	int i = 0;
	assert(pSeq);
	Judge_Full(pSeq);
	for (i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->Data[i + 1] = pSeq->Data[i];
	}
	pSeq->Data[0] = x;
	pSeq->size++;
}
void Pop_front(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i<pSeq->size; i++)
	{
		pSeq->Data[i] = pSeq->Data[i + 1];
	}
	pSeq->size--;
}
void Insert_SeqList(pSeqList pSeq, int pos, DataType x)      
{
	//在指定指定位置插入元素x，pos是下标
	int i = 0;
	assert(pSeq);
	Judge_Full(pSeq);
	for (i = pSeq->size - 1; i >= pos; i--)
	{
		pSeq->Data[i + 1] = pSeq->Data[i];
	}
	pSeq->Data[pos] = x;
	pSeq->size++;
}
void Remove_SeqList(pSeqList pSeq, DataType x) 
{
	int i = 0;
	int ret = 0;
	ret = Find_NUM(pSeq, x);
	assert(pSeq);
	if (ret == -1)
	{
		printf("顺序表中没有此元素\n");
		return;
	}
	else
	{
		for (i = ret; i<pSeq->size; i++)
		{
			pSeq->Data[i] = pSeq->Data[i + 1];
		}
	}
	pSeq->size--;
	printf("删除成功\n");
}
int Find_NUM(pSeqList pSeq, DataType x)  
{
	int i = 0;
	for (i = 0; i<pSeq->size; i++)
	{
		if (pSeq->Data[i] == x)
			return i;
	}
	return -1;
}

void RemoveAll_SeqList(pSeqList pSeq, DataType x) 
{
	int i = 0;
	int j = 0;
	int ret = 0;
	assert(pSeq);
	while (ret < pSeq->size)
	{
		ret = Find_NUM(pSeq, x);
		if (ret == -1)
		{
			printf("顺序表中没有此元素\n");
			return;
		}
		else
		{
			for (i = ret; i<pSeq->size; i++)
			{
				pSeq->Data[i] = pSeq->Data[i + 1];
			}
		}
		pSeq->size--;
		ret++;
	}
	printf("删除成功\n");
}
void Bubble_Sort(pSeqList pSeq)//冒泡排序
{
	int i = 0;
	int j = 0;
	int m = 0;
	DataType tmp = 0;
	int flag = 0;
	int k = pSeq->size - 1;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		m = 0;
		flag = 0;//对冒泡排序的优化
		for (j = 0; j < k; j++)//每一次运行到上一次结束为止结束
		{
			if (pSeq->Data[j]>pSeq->Data[j + 1])//升序
			{
				tmp = pSeq->Data[j];
				pSeq->Data[j] = pSeq->Data[j + 1];
				pSeq->Data[j + 1] = tmp;
				flag = 1;
				m = j;//记录最后一次交换的位置
			}
		}
		if (flag == 0)
			break;
		k = m;//k记录最后一次交换的位置
	}
}
void Insertion_Sort(pSeqList pSeq)//直接插入排序
{
	int i = 0;
	int j = 0;
	int k = 0;
	DataType tmp = 0;
	for (i = 1; i < pSeq->size; i++)
	{
		tmp = pSeq->Data[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (pSeq->Data[i] >= pSeq->Data[j])//升序
			{
				break;
			}
		}
		for (k = i - 1; k>j; k--)
		{
			//移出空位置，插入tmp
			pSeq->Data[k + 1] = pSeq->Data[k];
		}
		pSeq->Data[j + 1] = tmp;
	}
}
void Select_Sort(pSeqList pSeq)
{
	//选择排序（升）
	int i = 0; int j = 0; int min = 0;
	for (i = 0; i < pSeq->size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < pSeq->size; j++)
		{
			if (pSeq->Data[j] < pSeq->Data[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			//找到最小值的下标和初始的i值不同，交换
			DataType tmp = pSeq->Data[i];
			pSeq->Data[i] = pSeq->Data[min];
			pSeq->Data[min] = tmp;
		}
	}
}
int Binary_Search(pSeqList pSeq, DataType x)
{
	int left = 0;
	int mid = 0;
	int right = pSeq->size - 1;
	assert(pSeq);
	Bubble_Sort(pSeq);
	while (left<right)
	{
		mid = (left + right) / 2;
		if (pSeq->Data[mid] < x)
		{
			left = mid;
		}
		else if (pSeq->Data[mid]>x)
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
void Free_SeqList(pSeqList pSeq)
{
	free(pSeq->Data);
	pSeq->Data = NULL;
	exit(0);
}