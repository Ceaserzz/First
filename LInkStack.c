#include "C:\Users\Ceaser\Desktop\QG训练营\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


Status initLStack(LinkStack* s) {             //初始化栈
	s->top = NULL;
	s->count = 0;
}
Status isEmptyLStack(LinkStack* s) {              //判断栈是否为空
	if (s->count == 0)
	{
		printf("该栈为空。");
		return SUCCESS;
	}
	printf("该栈不为空。");
	return ERROR;
}


Status getTopLStack(LinkStack* s, ElemType* e) {     //得到栈顶元素
	if (s->count == 0)
	{
		printf("该栈为空。");
		return ERROR;
	}

	*e = s->top->data;
	return SUCCESS;
}


Status clearLStack(LinkStack* s) {         //清空栈
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

Status destroyLStack(LinkStack* s) {        //销毁栈
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

Status LStackLength(LinkStack* s, int* length) {         //检测栈长度
	*length = s->count;
	return SUCCESS;
}


Status pushLStack(LinkStack* s, ElemType data) {            //入栈
	LinkStackPtr p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
	
}


Status popLStack(LinkStack* s, ElemType* data) {         //出栈
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