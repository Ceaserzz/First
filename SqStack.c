#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


Status initStack(SqStack* s, int sizes) {                      //��ʼ��ջ 

	s->elem = malloc(sizeof(ElemType)*sizes);
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}


Status isEmptyStack(SqStack* s) {                               //�ж�ջ�Ƿ�Ϊ��

	if (s->top == -1) {
		printf("��ջΪ�ա�");
		return SUCCESS;
	}
	printf("��ջ��Ϊ�ա�");
	 return ERROR;
}


Status getTopStack(SqStack* s, ElemType* e) {                   //�õ�ջ��Ԫ��

	if (s->top == -1)
	{
		printf("�×CΪ�ա�");
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;
}


Status clearStack(SqStack* s) {                                //���ջ
	if (s == NULL)
	{
		return SUCCESS;
	}
	for (size_t i = 0; i < s->top; i++)
	{
		s->elem[s->top] = NULL;
	}
	s->top = -1;
	return SUCCESS;
}


Status destroyStack(SqStack* s) {                             //����ջ
	if (s == NULL)
	{
		return SUCCESS;
	}

	free(s);
	return SUCCESS;
}


Status stackLength(SqStack* s, int* length) {                  //���ջ����

	*length = s->size;
	return SUCCESS;
}


Status pushStack(SqStack* s, ElemType data) {                //��ջ

	if (s->top == s->size-1)
	{
		printf("�×C������");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;

}



Status popStack(SqStack* s, ElemType* data) {             //��ջ

	if (s->top == -1)
	{
		printf("�×CΪ�ա�");
		return ERROR;
	}
	while (s->elem[s->top] != *data)
	{
		s->top--;
	}
	return SUCCESS;

}

