// SeqList_dynamic.cpp : �������̨Ӧ�ó������ڵ㡣
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
	if (NULL == pSeq->Data)//��ֹ��ֵ����
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
		//��ָ��ָ�룬���·���ռ��С�����ʧ���򷵻ؿ�ָ��NULL
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
		printf("˳����ѿ�\n");
		return;
	}
	pSeq->size--;
}
void Push_front(pSeqList pSeq, DataType x)   
{
	//��˳����ǰ�����Ԫ��   
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
	//��ָ��ָ��λ�ò���Ԫ��x��pos���±�
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
		printf("˳�����û�д�Ԫ��\n");
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
	printf("ɾ���ɹ�\n");
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
			printf("˳�����û�д�Ԫ��\n");
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
	printf("ɾ���ɹ�\n");
}
void Bubble_Sort(pSeqList pSeq)//ð������
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
		flag = 0;//��ð��������Ż�
		for (j = 0; j < k; j++)//ÿһ�����е���һ�ν���Ϊֹ����
		{
			if (pSeq->Data[j]>pSeq->Data[j + 1])//����
			{
				tmp = pSeq->Data[j];
				pSeq->Data[j] = pSeq->Data[j + 1];
				pSeq->Data[j + 1] = tmp;
				flag = 1;
				m = j;//��¼���һ�ν�����λ��
			}
		}
		if (flag == 0)
			break;
		k = m;//k��¼���һ�ν�����λ��
	}
}
void Insertion_Sort(pSeqList pSeq)//ֱ�Ӳ�������
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
			if (pSeq->Data[i] >= pSeq->Data[j])//����
			{
				break;
			}
		}
		for (k = i - 1; k>j; k--)
		{
			//�Ƴ���λ�ã�����tmp
			pSeq->Data[k + 1] = pSeq->Data[k];
		}
		pSeq->Data[j + 1] = tmp;
	}
}
void Select_Sort(pSeqList pSeq)
{
	//ѡ����������
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
			//�ҵ���Сֵ���±�ͳ�ʼ��iֵ��ͬ������
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