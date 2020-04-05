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


//��������ת���ɾ����±�
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


// �����������Ƚ�
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


	// ת���±�
	int c1_index = getIndex(c1);
	int c2_index = getIndex(c2);
	
	
	// ����
	result = priorityMatrix[c1_index][c2_index];
	switch (result) {
	case '<': return -1; // c1<c2
	case '>': return 1; // c1>c2
	case '=': return 0; // c1=c2�������
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

//���ʽ��ֵ���涨Ϊ������δ����쳣
/* ��������:
10+11+12#
10*(1*(2+6/3)-1)+3^(3-1)+1+1-2#
 */
int main(void) {
	SqStack symbol; //��ŷ���
	SqStack figure; //�����ֵ
	char c; //ÿ�λ�õ��ַ�
	int num, S1, S2, result, tmp, OP; //�������
	//��ʼ��
	InitStack(&symbol);
	Push(&symbol, '#');
	InitStack(&figure);

	printf("��������ʽ(��#��β)��\n");
	c = getchar();
	num = 0;
	while (!StackEmpty(symbol)) {
		if (c >= '0' && c <= '9') { //����
			num = num * 10 + c - '0'; //��������
		}
		else { //������
			if (num != 0) { //֮ǰ������
				Push(&figure, num); //��ջ
				num = 0; //��Ϊ0
			}
			GetTop(symbol, &OP); //ȡ��������ջ��Ԫ��
			//����һ�����űȽ����ȼ�
			tmp = compare_op((char)c, (char)OP);
			if (tmp == 1) { //c>tmp
				Push(&symbol, c); //ѹջ
			}
			else if (tmp == -1) { //c<tmp
				Pop(&symbol, &OP);
				Pop(&figure, &S2); //��ȡ�����Ǻ���һλ������ 
				Pop(&figure, &S1);
				result = Operate(S1, (char)OP, S2);
				Push(&figure, result);
				continue; //��ִ��c=getchar()����ǰ��c��û�д�����
			}
			else if (tmp == 0) {
				// 1. c=) OP=(
				// 2. c=# OP=#
				Pop(&symbol, &tmp); //��ջ��ɾ��
			}

		}
		c = getchar();
	}
	GetTop(figure, &result);
	printf("\n��������%d\n", result);
	return 0;
}
