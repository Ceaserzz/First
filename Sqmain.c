#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void print(SqStack S);

int main(void) {
	SqStack L;
	int len = 0;
	int size = 5;
	int date = 1;
	int Num[4] = { 2,3,4,5 };

	printf("ջ�Ĵ�СΪsize=%d������һ����date=%d��һ����len=%d���Լ�һ����Num[4]={2,3,4,5}��",size,date,len);
	initStack(&L, size);       //��ջ���г�ʼ��
	
	printf("\n----------------�����ж�ջ�Ƿ�Ϊ�ղ������ջ�ĳ���---------------\n");
	isEmptyStack(&L);
	stackLength(&L, &len);
	printf("����Ϊ%d", len);

	printf("\n----------------����Ϊ��date����ջ������ջ�����ұ���---------------\n");
	pushStack(&L, date);
	print(L);
	
	printf("\n----------------�����ж�ջ�Ƿ�Ϊ�ղ��ҵõ�ջ��Ԫ��---------------\n");
	isEmptyStack(&L);
	getTopStack(&L, &date);
	printf("date=%d", date);
	
	printf("\n----------------���潫�����ڵ�Ԫ������ջ������ջ�����ұ���ͬʱ�õ�ջ��Ԫ��---------------\n");
	pushStack(&L, Num[0]);
	pushStack(&L, Num[1]);
	pushStack(&L, Num[2]);
	pushStack(&L, Num[3]);
	print(L);
	getTopStack(&L, &date);
	printf("date=%d", date);

	printf("\n----------------���潫ջ��ղ��ж��Ƿ�Ϊ��---------------\n");
	clearStack(&L);
	isEmptyStack(&L);

	printf("\n----------------���ջ����---------------\n");
	destroyStack(&L);

}

void print(SqStack S) {
	printf("��ջ��ջ�׵�ջ���ֱ�Ϊ��");
	for (size_t i = 0; i <= S.top; i++)
	{
		printf("%d\t", S.elem[i]);
	}
}