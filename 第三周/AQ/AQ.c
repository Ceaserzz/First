#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ��������ѵ\��ִ���ļ�\AQueue\AQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void InitAQueue(AQueue* Q) {     /*��ʼ������*/
	int i;
	Q->length = MAXQUEUE;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(MAXQUEUE);
	Q->front = Q->rear = 0;
}


void DestoryAQueue(AQueue* Q) {      /*���ٶ���*/
	if (Q->data[0] == NULL)
	{
		printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	Q->data[0] = NULL;
}


Status IsFullAQueue(const AQueue* Q) {   /* �������Ƿ�����*/
	if (Q->data[0] == NULL)
	{
		printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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


Status IsEmptyAQueue(const AQueue* Q) {    /*�������Ƿ�Ϊ��*/
	if (Q->data[0] == NULL)
	{
		printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	if (LengthAQueue(Q) == MAXQUEUE - 1)
	{
		return FALSE;
	}
	printf("����Ϊ��\n");
	return TRUE;
}


Status GetHeadAQueue(AQueue* Q, void* e) {    /*�鿴��ͷԪ��*/
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	e = Q->data[Q->front];
	return TRUE;

}


int LengthAQueue(AQueue* Q) {        /*ȷ�����г���*/
	return (Q->rear - Q->front + Q->length) % Q->length;
}


Status EnAQueue(AQueue* Q, void* data){    /*��Ӳ���*/     //ʵ�ڸ㲻��Ϊʲô������д����Ǵ��

	Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->data[Q->rear] = data;
	return TRUE;
}


Status DeAQueue(AQueue* Q) {          /*���Ӳ���*/
	if (Q->front == Q->rear)
	{
		printf("����Ϊ��");
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length;
	return TRUE;
}


void ClearAQueue(AQueue* Q) {         /*��ն���*/
	if (Q->front == Q->rear)
	{
		printf("����Ϊ��");
		return;
	}
	Q->front = Q->rear = 0;
}


Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int size)) {       /* ������������*/
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


void APrint(void* q,int size) {            /* ��������*/
	if (size == sizeof(double))
		printf("%lf", *(double*)q);
	if (size == sizeof(char))
		printf("%c", *(char*)q);
	if (size == sizeof(int))
		printf("%d", *(int*)q);

}