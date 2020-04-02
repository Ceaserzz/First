#include <stdio.h>

#include <stdlib.h>
#include <malloc.h>
#include "../head/duLinkedList.h"


int main(void) {
    DuLinkedList L;
    DuLinkedList L2;
    DuLNode n;
    n.data = 50;
    ElemType num = 10;
    printf("num=%d\n", num);
    printf("n.data=%d\n", n.data);
    printf("请输入链表元素，当输入999时停止输入。");
    CreatList(&L);  //建立双链表
    printf("\n--------------以下为建立的双链表--------------\n");
    TraverseList_DuL(L,print_date);  //遍历链表并调用函数访问
    printf("\n--------------以下为删除掉第二个节点后并将值赋给num后的链表与num--------------\n");
    DeleteList_DuL(L->next->next, &num);  //删除节点p之后的第一个节点，并将其值赋给e
    printf("num=%d\n", num);
    TraverseList_DuL(L, print_date);
    printf("\n--------------以下为在第二个节点前插入节点n的链表--------------\n");
    InsertBeforeList_DuL(L->next->next, &n);
    TraverseList_DuL(L, print_date);
    printf("\n--------------以下为销毁链表--------------\n");
    DestroyList_DuL(&L);
    TraverseList_DuL(L, print_date);
}
//2号凌晨一点四十，睡了睡了

