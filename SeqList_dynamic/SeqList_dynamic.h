#define _CRT_SECURE_NO_WARNINGS    
#ifndef __SEQLIST_D_H__    //多个.c文件多次调用此.h文件，防止重复载入  
#define __SEQLIST_D_H__  
#include<stdio.h>    
#include<stdlib.h>    
#include<string.h>    
#include<assert.h>    

#define MAX 100    
#define MAX_INIT 3  
#define MAX_ADD 3  
typedef int DataType;

typedef struct SeqList
{
	DataType *Data;
	int size;
	int capacity; 
}SeqList, *pSeqList;

void menu();
void Print_SeqList(pSeqList pSeq);           
void Init_SeqList(pSeqList pSeq);         
void Judge_Full(pSeqList pSeq);   //判断当前空间是否满了        
void Free_SeqList(pSeqList pSeq);          
void Push_Back(pSeqList pSeq, DataType x);     
void Pop_Back(pSeqList pSeq);             
void Push_front(pSeqList pSeq, DataType x);    
void Pop_front(pSeqList pSeq);   
void Insert_SeqList(pSeqList pSeq, int pos, DataType x);    
void Remove_SeqList(pSeqList pSeq, DataType x);       
void RemoveAll_SeqList(pSeqList pSeq, DataType x); 
void Bubble_Sort(pSeqList pSeq);       
void Insertion_Sort(pSeqList pSeq); 
void Select_Sort(pSeqList pSeq);  
int Find_NUM(pSeqList pSeq, DataType x);
int Binary_Search(pSeqList pSeq, DataType x);
#endif 