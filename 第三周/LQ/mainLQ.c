#include "C:\Users\Ceaser\Desktop\QG训练营\QG训练营第三次培训\可执行文件\LQueue\LQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int main(void) {
	LQueue L;
	int len = 0;
	int date = 1;
	int Num[4] = { 2,3,4,5 };
	printf("\n----------------和刚刚的循环队列一样，我测试不出我的代码错哪，害，不写泛型就可以，写泛型实在看不出哪里有问题---------------\n");
	printf("现有一整数date=%d，一整数len=%d，以及一数组Num[4]={2,3,4,5}。", date, len);
	InitLQueue(&L);       //对队列进行初始化

	printf("\n----------------下面判断队列是否为空并且确定队列的长度---------------\n");
	IsEmptyLQueue(&L);
	len = LengthLQueue(&L);
	printf("\n长度为%d", len);

	printf("\n----------------下面为将date输入队列并且遍历---------------\n");
	EnLQueue(&L, &date);
	TraverseLQueue(&L, LPrint);

	printf("\n----------------下面判断队列是否为空并且得到队列头元素---------------\n");
	IsEmptyLQueue(&L);
	GetHeadLQueue(&L, &date);
	printf("\ndate=%d", date);

	printf("\n----------------下面将数组内的元素输入队列并且遍历同时得到队列头元素并且确定队列的长度---------------\n");
	EnLQueue(&L, Num[0]);
	EnLQueue(&L, Num[1]);
	EnLQueue(&L, Num[2]);
	EnLQueue(&L, Num[3]);
	TraverseLQueue(&L, LPrint);
	GetHeadLQueue(&L, &date);
	printf("\ndate=%d", date);
	len = LengthLQueue(&L);
	printf("\n长度为%d", len);


	printf("\n----------------下面将两个数字进行出队操作并且遍历同时得到队列头元素并且确定队列的长度---------------\n");
	DeLQueue(&L);
	DeLQueue(&L);
	TraverseLQueue(&L, LPrint);
	GetHeadLQueue(&L, &date);
	printf("\ndate=%d", date);
	len = LengthLQueue(&L);
	printf("\n长度为%d", len);

	printf("\n----------------下面将队列清空并判断是否为空---------------\n");
	ClearLQueue(&L);
	IsEmptyLQueue(&L);

	printf("\n----------------最后将栈销毁---------------\n");
	DestoryLQueue(&L);

}