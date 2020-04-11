#include "C:\Users\Ceaser\Desktop\QG训练营\QG训练营第三次培训\可执行文件\AQueue\AQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void InitAQueue(AQueue* Q) {     /*初始化队列*/
	int i;
	Q->length = MAXQUEUE;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(MAXQUEUE);
	Q->front = Q->rear = 0;
}


void DestoryAQueue(AQueue* Q) {      /*销毁队列*/
	if (Q->data[0] == NULL)
	{
		printf("队列目前未初始化！请先初始化队列！\n");
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	Q->data[0] = NULL;
}


Status IsFullAQueue(const AQueue* Q) {   /* 检查队列是否已满*/
	if (Q->data[0] == NULL)
	{
		printf("队列目前未初始化！请先初始化队列！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q)) {
		return FALSE;
	}
	if (LengthAQueue(Q) == MAXQUEUE - 1)
	{
		return TRUE;
	}
}


Status IsEmptyAQueue(const AQueue* Q) {    /*检查队列是否为空*/
	if (Q->data[0] == NULL)
	{
		printf("队列目前未初始化！请先初始化队列！\n");
		return FALSE;
	}
	if (LengthAQueue(Q) == MAXQUEUE - 1)
	{
		return FALSE;
	}
	printf("队列为空\n");
	return TRUE;
}


Status GetHeadAQueue(AQueue* Q, void* e) {    /*查看队头元素*/
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	e = Q->data[Q->front];
	return TRUE;

}


int LengthAQueue(AQueue* Q) {        /*确定队列长度*/
	return (Q->rear - Q->front + Q->length) % Q->length;
}


Status EnAQueue(AQueue* Q, void* data){    /*入队操作*/     //实在搞不定为什么我这样写入队是错的

	Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->data[Q->rear] = data;
	return TRUE;
}


Status DeAQueue(AQueue* Q) {          /*出队操作*/
	if (Q->front == Q->rear)
	{
		printf("队列为空");
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length;
	return TRUE;
}


void ClearAQueue(AQueue* Q) {         /*清空队列*/
	if (Q->front == Q->rear)
	{
		printf("队列为空");
		return;
	}
	Q->front = Q->rear = 0;
}


Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int size)) {       /* 遍历函数操作*/
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[i], Q->length);
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;

}


void APrint(void* q,int size) {            /* 操作函数*/
	if (size == sizeof(double))
		printf("%lf", *(double*)q);
	if (size == sizeof(char))
		printf("%c", *(char*)q);
	if (size == sizeof(int))
		printf("%d", *(int*)q);

}