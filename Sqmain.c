#include "C:\Users\Ceaser\Desktop\QG训练营\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h"
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

	printf("栈的大小为size=%d，现有一整数date=%d，一整数len=%d，以及一数组Num[4]={2,3,4,5}。",size,date,len);
	initStack(&L, size);       //对栈进行初始化
	
	printf("\n----------------下面判断栈是否为空并且输出栈的长度---------------\n");
	isEmptyStack(&L);
	stackLength(&L, &len);
	printf("长度为%d", len);

	printf("\n----------------下面为将date输入栈进行入栈处理并且遍历---------------\n");
	pushStack(&L, date);
	print(L);
	
	printf("\n----------------下面判断栈是否为空并且得到栈顶元素---------------\n");
	isEmptyStack(&L);
	getTopStack(&L, &date);
	printf("date=%d", date);
	
	printf("\n----------------下面将数组内的元素输入栈进行入栈处理并且遍历同时得到栈顶元素---------------\n");
	pushStack(&L, Num[0]);
	pushStack(&L, Num[1]);
	pushStack(&L, Num[2]);
	pushStack(&L, Num[3]);
	print(L);
	getTopStack(&L, &date);
	printf("date=%d", date);

	printf("\n----------------下面将栈清空并判断是否为空---------------\n");
	clearStack(&L);
	isEmptyStack(&L);

	printf("\n----------------最后将栈销毁---------------\n");
	destroyStack(&L);

}

void print(SqStack S) {
	printf("该栈从栈底到栈顶分别为：");
	for (size_t i = 0; i <= S.top; i++)
	{
		printf("%d\t", S.elem[i]);
	}
}