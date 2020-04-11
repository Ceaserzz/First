#include "C:\Users\Ceaser\Desktop\QG训练营\QG训练营第三次培训\可执行文件\AQueue\AQueue2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main(void) {
	AQueue L;
	int len = 0;
	int date = 1;
	int Num[4] = { 2,3,4,5 };
	printf("\n----------------因为入队函数怎么写都不行，所以后面的测试基本测试不了---------------\n");
	printf("队列的大小为size=%d，现有一整数date=%d，一整数len=%d，以及一数组Num[4]={2,3,4,5}。", MAXQUEUE, date, len);
	InitAQueue(&L);       //对队列进行初始化

	printf("\n----------------下面判断队列是否为空并且确定队列的长度---------------\n");
	IsEmptyAQueue(&L);
	len = LengthAQueue(&L);
	printf("长度为%d", len);

	printf("\n----------------下面为将date输入队列并且遍历---------------\n");
	EnAQueue(&L, &date);
	TraverseAQueue(&L, APrint);

	printf("\n----------------下面判断队列是否为空并且得到队列头元素---------------\n");
	IsEmptyAQueue(&L);
	GetHeadAQueue(&L, &date);
	printf("date=%d", date);

	printf("\n----------------下面将数组内的元素输入队列并且遍历并且确定队列的长度同时判断是否队列已满---------------\n");
	EnAQueue(&L, Num[0]);
	EnAQueue(&L, Num[1]);
	EnAQueue(&L, Num[2]);
	EnAQueue(&L, Num[3]);
	TraverseAQueue(&L, APrint);
	printf("date=%d", date);
	len = LengthAQueue(&L);
	printf("长度为%d", len);
	IsFullAQueue(&L);

	printf("\n----------------下面将两个数字进行出队操作并且遍历并且确定队列的长度---------------\n");
	DeAQueue(&L);
	DeAQueue(&L);
	TraverseAQueue(&L, APrint);
	printf("date=%d", date);
	len = LengthAQueue(&L);
	printf("长度为%d", len);

	printf("\n----------------下面将队列清空并判断是否为空---------------\n");
	ClearAQueue(&L);
	IsEmptyAQueue(&L);

	printf("\n----------------最后将栈销毁---------------\n");
	DestoryAQueue(&L);

}