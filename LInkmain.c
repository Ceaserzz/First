#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void Out(LinkStack s);

int main(void) {
	LinkStack L;
	int len = 0;
	int size = 5;
	int date = 1;
	int Num[4] = { 2,3,4,5 };

	printf("ջ�Ĵ�СΪsize=%d������һ����date=%d��һ����len=%d���Լ�һ����Num[4]={2,3,4,5}��", size, date, len);
	initLStack(&L, size);       //��ջ���г�ʼ��

	printf("\n----------------�����ж�ջ�Ƿ�Ϊ�ղ������ջ�ĳ���---------------\n");
	isEmptyLStack(&L);
	LStackLength(&L, &len);
	printf("����Ϊ%d", len);

	printf("\n----------------����Ϊ��date����ջ������ջ�����ұ���---------------\n");
	pushLStack(&L, date);
	Out(L);

	printf("\n----------------�����ж�ջ�Ƿ�Ϊ�ղ��ҵõ�ջ��Ԫ��---------------\n");
	isEmptyLStack(&L);
	getTopLStack(&L, &date);
	printf("date=%d", date);

	printf("\n----------------���潫�����ڵ�Ԫ������ջ������ջ�����ұ���ͬʱ�õ�ջ��Ԫ��---------------\n");
	pushLStack(&L, Num[0]);
	pushLStack(&L, Num[1]);
	pushLStack(&L, Num[2]);
	pushLStack(&L, Num[3]);
	Out(L);
	getTopLStack(&L, &date);
	printf("date=%d", date);

	printf("\n----------------���潫ջ��ղ��ж��Ƿ�Ϊ��---------------\n");
	clearLStack(&L);
	isEmptyLStack(&L);

	printf("\n----------------���ջ����---------------\n");
	destroyLStack(&L);

}




void Out(LinkStack s) {
	LinkStackPtr p = s.top;
	printf("ջ��ջ�׵�ջ���ֱ���:");
	while (p)
	{
		printf("\t%d\t", p->data);
		p = p->next;
	}
}