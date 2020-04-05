#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"SqStack.h"

void visit(ElemType e) {
	printf("%d ", e);
}
void visit_optr(ElemType e) {
	printf("%c ", e);
}


//将操作符转换成矩阵下标
int getIndex(char c) {
	switch (c) {
	case '+': return 0;
	case '-': return 1;
	case '*': return 2;
	case '/': return 3;
	case '(': return 4;
	case ')': return 5;
	case '^': return 6;
	case '#': return 7;
	}
	return -1;
}


// 两个操作数比较
int compare_op(char c1, char c2) {
	char result;
	static char priorityMatrix[8][8] =
	{  // +   -   *   /   (   )   ^   #
		{'<','<','<','<','>','<','<','>'}, //+
		{'<','<','<','<','>','<','<','>'}, //-
		{'>','>','<','<','>','<','<','>'}, //*
		{'>','>','<','<','>','<','<','>'}, ///
		{'>','>','>','>','>','>','>','>'}, //(
		{'<','<','<','<','=','<','<','>'}, //)
		{'>','>','>','>','>','<','>','>'}, //^
		{'<','<','<','<','<','<','<','='}  //#
	};


	// 转换下标
	int c1_index = getIndex(c1);
	int c2_index = getIndex(c2);
	
	
	// 矩阵
	result = priorityMatrix[c1_index][c2_index];
	switch (result) {
	case '<': return -1; // c1<c2
	case '>': return 1; // c1>c2
	case '=': return 0; // c1=c2错误情况
	}
	return 0;
}
int Operate(int S1, char OP, int S2) {
	switch (OP) {
	case '+':
		return S1 + S2;
	case '-':
		return S1 - S2;
	case '*':
		return S1 * S2;
	case '/':
		return S1 / S2;

	case '^':
		return (int)pow(S1, S2);
	}
	return 0;
}

//表达式求值：规定为整数，未检查异常
/* 测试数据:
10+11+12#
10*(1*(2+6/3)-1)+3^(3-1)+1+1-2#
 */
int main(void) {
	SqStack symbol; //存放符号
	SqStack figure; //存放数值
	char c; //每次获得的字符
	int num, S1, S2, result, tmp, OP; //存放数字
	//初始化
	InitStack(&symbol);
	Push(&symbol, '#');
	InitStack(&figure);

	printf("请输入表达式(以#结尾)：\n");
	c = getchar();
	num = 0;
	while (!StackEmpty(symbol)) {
		if (c >= '0' && c <= '9') { //数字
			num = num * 10 + c - '0'; //保存数字
		}
		else { //操作符
			if (num != 0) { //之前有数字
				Push(&figure, num); //入栈
				num = 0; //归为0
			}
			GetTop(symbol, &OP); //取出操作符栈顶元素
			//与上一个符号比较优先级
			tmp = compare_op((char)c, (char)OP);
			if (tmp == 1) { //c>tmp
				Push(&symbol, c); //压栈
			}
			else if (tmp == -1) { //c<tmp
				Pop(&symbol, &OP);
				Pop(&figure, &S2); //先取出的是后面一位的数字 
				Pop(&figure, &S1);
				result = Operate(S1, (char)OP, S2);
				Push(&figure, result);
				continue; //不执行c=getchar()，当前的c还没有处理完
			}
			else if (tmp == 0) {
				// 1. c=) OP=(
				// 2. c=# OP=#
				Pop(&symbol, &tmp); //将栈顶删除
			}

		}
		c = getchar();
	}
	GetTop(figure, &result);
	printf("\n计算结果：%d\n", result);
	return 0;
}
