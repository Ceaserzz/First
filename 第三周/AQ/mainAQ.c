#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ��������ѵ\��ִ���ļ�\AQueue\AQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main(void) {
	AQueue L;
	int len = 0;
	int date = 1;
	int Num[4] = { 2,3,4,5 };
	printf("\n----------------��Ϊ��Ӻ�����ôд�����У����Ժ���Ĳ��Ի������Բ���---------------\n");
	printf("���еĴ�СΪsize=%d������һ����date=%d��һ����len=%d���Լ�һ����Num[4]={2,3,4,5}��", MAXQUEUE, date, len);
	InitAQueue(&L);       //�Զ��н��г�ʼ��

	printf("\n----------------�����ж϶����Ƿ�Ϊ�ղ���ȷ�����еĳ���---------------\n");
	IsEmptyAQueue(&L);
	len = LengthAQueue(&L);
	printf("����Ϊ%d", len);

	printf("\n----------------����Ϊ��date������в��ұ���---------------\n");
	EnAQueue(&L, &date);
	TraverseAQueue(&L, APrint);

	printf("\n----------------�����ж϶����Ƿ�Ϊ�ղ��ҵõ�����ͷԪ��---------------\n");
	IsEmptyAQueue(&L);
	GetHeadAQueue(&L, &date);
	printf("date=%d", date);

	printf("\n----------------���潫�����ڵ�Ԫ��������в��ұ�������ȷ�����еĳ���ͬʱ�ж��Ƿ��������---------------\n");
	EnAQueue(&L, Num[0]);
	EnAQueue(&L, Num[1]);
	EnAQueue(&L, Num[2]);
	EnAQueue(&L, Num[3]);
	TraverseAQueue(&L, APrint);
	printf("date=%d", date);
	len = LengthAQueue(&L);
	printf("����Ϊ%d", len);
	IsFullAQueue(&L);

	printf("\n----------------���潫�������ֽ��г��Ӳ������ұ�������ȷ�����еĳ���---------------\n");
	DeAQueue(&L);
	DeAQueue(&L);
	TraverseAQueue(&L, APrint);
	printf("date=%d", date);
	len = LengthAQueue(&L);
	printf("����Ϊ%d", len);

	printf("\n----------------���潫������ղ��ж��Ƿ�Ϊ��---------------\n");
	ClearAQueue(&L);
	IsEmptyAQueue(&L);

	printf("\n----------------���ջ����---------------\n");
	DestoryAQueue(&L);

}