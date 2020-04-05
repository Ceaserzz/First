#include "C:\Users\Ceaser\Desktop\QGѵ��Ӫ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


Status initLStack(LinkStack* s) {             //��ʼ��ջ
	s->top = NULL;
	s->count = 0;
}
Status isEmptyLStack(LinkStack* s) {              //�ж�ջ�Ƿ�Ϊ��
	if (s->count == 0)
	{
		printf("��ջΪ�ա�");
		return SUCCESS;
	}
	printf("��ջ��Ϊ�ա�");
	return ERROR;
}


Status getTopLStack(LinkStack* s, ElemType* e) {     //�õ�ջ��Ԫ��
	if (s->count == 0)
	{
		printf("��ջΪ�ա�");
		return ERROR;
	}

	*e = s->top->data;
	return SUCCESS;
}


Status clearLStack(LinkStack* s) {         //���ջ
	if (s == NULL)
	{
		return ERROR;
	}
	LinkStackPtr p, q;
	p = s->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

Status destroyLStack(LinkStack* s) {        //����ջ
	if (s==NULL)
	{
		return ERROR;
	}
	LinkStackPtr p, q;
	p = s->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(s->top);
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length) {         //���ջ����
	*length = s->count;
	return SUCCESS;
}


Status pushLStack(LinkStack* s, ElemType data) {            //��ջ
	LinkStackPtr p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
	
}


Status popLStack(LinkStack* s, ElemType* data) {         //��ջ
	if (s->top==NULL)
	{
		return ERROR;
	}
	StackNode* p = s->top;
	*data = s->top->data;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;

}