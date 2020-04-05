#include "C:\Users\Ceaser\Desktop\QG训练营\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


Status initStack(SqStack* s, int sizes) {                      //初始化栈 

	s->elem = malloc(sizeof(ElemType)*sizes);
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}


Status isEmptyStack(SqStack* s) {                               //判断栈是否为空

	if (s->top == -1) {
		printf("该栈为空。");
		return SUCCESS;
	}
	printf("该栈不为空。");
	 return ERROR;
}


Status getTopStack(SqStack* s, ElemType* e) {                   //得到栈顶元素

	if (s->top == -1)
	{
		printf("该桟为空。");
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;
}


Status clearStack(SqStack* s) {                                //清空栈
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


Status destroyStack(SqStack* s) {                             //销毁栈
	if (s == NULL)
	{
		return SUCCESS;
	}

	free(s);
	return SUCCESS;
}


Status stackLength(SqStack* s, int* length) {                  //检测栈长度

	*length = s->size;
	return SUCCESS;
}


Status pushStack(SqStack* s, ElemType data) {                //入栈

	if (s->top == s->size-1)
	{
		printf("该桟已满。");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;

}



Status popStack(SqStack* s, ElemType* data) {             //出栈

	if (s->top == -1)
	{
		printf("该桟为空。");
		return ERROR;
	}
	while (s->elem[s->top] != *data)
	{
		s->top--;
	}
	return SUCCESS;

}

