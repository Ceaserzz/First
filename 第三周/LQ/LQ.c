#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ��������ѵ\��ִ���ļ�\LQueue\LQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
void InitLQueue(LQueue* Q) {    /*��ʼ������*/
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
}


void DestoryLQueue(LQueue* Q) {        /*���ٶ���*/
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}


Status IsEmptyLQueue(const LQueue* Q) {     /*�������Ƿ�Ϊ��*/
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}


Status GetHeadLQueue(LQueue* Q, void* e) {     /*�鿴��ͷԪ��*/
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(&e, Q->front->next->data, Q->length);
	return TRUE;
}


int LengthLQueue(LQueue* Q) {            /*ȷ�����г���*/
	int length;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}


Status EnLQueue(LQueue* Q, void* data) {    /*��Ӳ���*/
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void*)malloc(Q->length);
	memcpy(p->data, data, Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;

}


Status DeLQueue(LQueue* Q) {        /*���Ӳ���*/
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)
		Q->rear = Q->front;
	free(p);
	return TRUE;
}


void ClearLQueue(LQueue* Q) {           /* ��ն���*/
	if(IsEmptyLQueue(Q))
		return;
	Node* p, * q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}


Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,int size)) {     /* ������������*/
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = (void*)malloc(Q->length);
	p = Q->front->next;
	int i = 1;
	while (p != NULL) {
		if (i % 5 == 0) printf("\n");
		foo(p->data, Q->length);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}


void LPrint(void* q, int size) {       /* ��������*/
	if (size == sizeof(double))
		printf("%lf", *(double*)q);
	if (size == sizeof(char))
		printf("%c", *(char*)q);
	if (size == sizeof(int))
		printf("%d", *(int*)q);
	printf("-<");

}