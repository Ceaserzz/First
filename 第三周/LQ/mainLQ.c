#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ��������ѵ\��ִ���ļ�\LQueue\LQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int main(void) {
	LQueue L;
	int len = 0;
	int date = 1;
	int Num[4] = { 2,3,4,5 };
	printf("\n----------------�͸ոյ�ѭ������һ�����Ҳ��Բ����ҵĴ�����ģ�������д���;Ϳ��ԣ�д����ʵ�ڿ���������������---------------\n");
	printf("����һ����date=%d��һ����len=%d���Լ�һ����Num[4]={2,3,4,5}��", date, len);
	InitLQueue(&L);       //�Զ��н��г�ʼ��

	printf("\n----------------�����ж϶����Ƿ�Ϊ�ղ���ȷ�����еĳ���---------------\n");
	IsEmptyLQueue(&L);
	len = LengthLQueue(&L);
	printf("\n����Ϊ%d", len);

	printf("\n----------------����Ϊ��date������в��ұ���---------------\n");
	EnLQueue(&L, &date);
	TraverseLQueue(&L, LPrint);

	printf("\n----------------�����ж϶����Ƿ�Ϊ�ղ��ҵõ�����ͷԪ��---------------\n");
	IsEmptyLQueue(&L);
	GetHeadLQueue(&L, &date);
	printf("\ndate=%d", date);

	printf("\n----------------���潫�����ڵ�Ԫ��������в��ұ���ͬʱ�õ�����ͷԪ�ز���ȷ�����еĳ���---------------\n");
	EnLQueue(&L, Num[0]);
	EnLQueue(&L, Num[1]);
	EnLQueue(&L, Num[2]);
	EnLQueue(&L, Num[3]);
	TraverseLQueue(&L, LPrint);
	GetHeadLQueue(&L, &date);
	printf("\ndate=%d", date);
	len = LengthLQueue(&L);
	printf("\n����Ϊ%d", len);


	printf("\n----------------���潫�������ֽ��г��Ӳ������ұ���ͬʱ�õ�����ͷԪ�ز���ȷ�����еĳ���---------------\n");
	DeLQueue(&L);
	DeLQueue(&L);
	TraverseLQueue(&L, LPrint);
	GetHeadLQueue(&L, &date);
	printf("\ndate=%d", date);
	len = LengthLQueue(&L);
	printf("\n����Ϊ%d", len);

	printf("\n----------------���潫������ղ��ж��Ƿ�Ϊ��---------------\n");
	ClearLQueue(&L);
	IsEmptyLQueue(&L);

	printf("\n----------------���ջ����---------------\n");
	DestoryLQueue(&L);

}