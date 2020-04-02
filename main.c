#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../head/linkedList.h"
LinkedList CreatLink(int a[], int n);
void PrintLink(LinkedList head);
//void goon();
LinkedList CreateSgLinkList(void);

int main(void) {
    int n;
    printf("请你输入链表的个数(写一个就够了哈，后面的测试我就用了一个链表)：");

    scanf_s("%d", &n);
    LNode* L;
    L= CreateSgLinkList();
    //LNode *L = NULL;
    //LNode *L2 = NULL;
    //int a[11] = { 11,2,5,8,4,7,6,9,0,10,25 };
    //int b[11] = { 11,1,2,3,4,5,6,7,8,9,10 };
    //L = CreatLink(a, 10);
    //L2 = CreatLink(b, 10);
    int num = 16;
    LinkedList head;  //空头节点
    LNode Node1;
    Node1.data = 18;
    LNode Node2;
    Node2.data = 20;
    printf("\n----------------------------\n");
    /*for (size_t i = 0; i < 10; i++)
    {
            printf("%d\t", a[i + 1]);
    }
    printf("\n----------------------------\n");
    for (size_t i = 0; i < 10; i++)
    {
            printf("%d\t", b[i + 1]);
    }
    printf("\n----------------------------\n");*/
    printf("Node1.date=%d\tNode2.date=%d", Node1.data, Node2.data);
    printf("\n----------------------------\n");
    InitList(&head);                             //测试函数只使用没有值的头节点初始化空链表
    printf("\n----------------------------\n");
    InsertList(L->next->next, &Node1);
    TraverseList(L, print_date);                 //测试遍历链表并调用函数
    printf("\n----------------------------\n");
    //printf("%d", num);
    //DeleteList(&L, &num);                      //测试删除节点p之后的第一个节点，并将其值赋给e
    //printf("%d", num);                         //很烦，运行时报异常，也不知道错在哪
    printf("\n----------------------------\n");
    printf("请输入你要查找的数字");
    int num2;
    scanf_s("%d", &num2);
    SearchList(L, num2);                       //测试根据e找到链表中的第一个节点
    printf("\n----------------------------\n");
    //ReverseList(&L);                           //测试反转链表
    //TraverseList(L, print_date);               //测试过后，始终不行，一直都是把链表销毁成只有头节点
    printf("\n----------------------------\n");
    IsLoopList(L);                               //测试是否为循环链表
    printf("\n----------------------------\n");
/*    ReverseEvenList(&L);                         //测试对链表中值为偶数的节点进行反向操作
    TraverseList(L, print_date);   */              //很不幸，运行时报异常，我觉得我要反思学习的意义了==
    printf("\n----------------------------\n");
    head = FindMidNode(&L);                        //测试寻找中间节点，这最后一个函数，总算是对的了
    printf("%d", head->data);                      //测试
    printf("\n----------------------------\n");
    //DestroyList(&L);                               //测试函数销毁一个链表，释放所有节点
    //TraverseList(L, print_date);                   //很遗憾，没能圆满结尾，运行到这里时，说触发了一个断点，害，很懵逼
    getchar();
    //纪念一下现在是4月2号凌晨一点四十，熬了那么多天夜，总算是搞定了作业，结果还是一堆不知道怎么修改的错的，难顶，害这数据结构可真不容易，还是得继续加油！！
}


LinkedList CreateSgLinkList(void)
{
    int i, length, data;
    LinkedList p_new = NULL, pTail = NULL;
    //创建头节点，头结点是第0个节点，后面的节点从1开始计数
    LinkedList pHead = (LinkedList)malloc(sizeof(LNode));

    if (NULL == pHead)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }

    pHead->data = 0;
    pHead->next = NULL;
    pTail = pHead;

    printf("请输入要创建链表的长度：");
    scanf_s("%d", &length);

    for (i = 1; i < length + 1; i++)
    {
        p_new = (LinkedList)malloc(sizeof(LNode));
        if (NULL == p_new)
        {
            printf("内存分配失败！\n");
            exit(EXIT_FAILURE);
        }

        printf("请输入第%d个节点的值：", i);
        scanf_s("%d", &data);

        p_new->data = data;
        p_new->next = NULL;
        pTail->next = p_new;
        pTail = p_new;
    }
    return pHead;
}


void PrintLink(LinkedList head)
{
    LinkedList p = head;
    for (; p; p = p->next)
        printf("%5d", p->data);
}

LinkedList CreatLink(int a[], int n)
{
    LNode* head, * tail, * p;
    head = NULL;
    tail = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        p->data = a[i];
        p->next = NULL;
        if (!head)
        {
            head = tail = p;
            tail->next = NULL;
        }
        else
        {
            tail = tail->next = p;
            tail->next = NULL;
        }
    }
    return head;
}




//int main(void) {
//    LinkedList L = NULL;
//    LinkedList L2 = NULL;
//    int a[11] = { 11,2,5,8,4,7,6,9,0,10,25 };
//    int b[11] = { 11,1,2,3,4,5,6,7,8,9,10 };
//    L = CreatLink(a, 10);
//    L2 = CreatLink(b, 10);
//    int num = 16;
//    LinkedList head;
//    LNode Node1;
//    Node1.data = 18;
//    LNode Node2;
//    Node2.data = 20;
//    printf("现有两个长度为10的链表以及一个整数一个头结点和两个节点，你可以对他们做以下操作。\n");
//    printf("\n----------------------------\n");
//    for (size_t i = 0; i < 10; i++)
//    {
//        printf("%d\t", a[i + 1]);
//    }
//    printf("\n----------------------------\n");
//    for (size_t i = 0; i < 10; i++)
//    {
//        printf("%d\t", b[i + 1]);
//    }
//    printf("\n----------------------------\n");
//    printf("Node1.date=%d\tNode2.date=%d", Node1.data, Node2.data);
//    printf("\n----------------------------\n");
//
//
//    printf("1.使用没有值的头节点初始化空链表\n");
//    printf("2.销毁一个链表，释放所有节点\n");
//    printf("3.在节点p之后插入节点q\n");
//    printf("4.删除节点p之后的第一个节点，并将其值赋给e\n");
//    printf("5.遍历链表并打印\n");
//    printf("6.根据e找到链表中的第一个节点\n");
//    printf("7.反转链表\n");
//    printf("8.判断链表是否循环\n");
//    printf("9.对链表中值为偶数的节点进行反向操作，输入:1 -> 2 -> 3 -> 4输出:2 -> 1 -> 4 -> 3\n");
//    printf("10.在链表中找到中间节点\n");
//    printf("\n----------------------------\n");
//    printf("按ESC退出程序\n");
//
//
//    char ckey = 'a';
//
//    //printf("%d\n", c);
//    //printf("\n----------------------------\n");
//    //TraverseList(L, print_date);
//    //printf("\n----------------------------\n");
//    //LNode mid = *FindMidNode(&L2);
//    //printf("%d\n", mid.data);
//    //printf("\n----------------------------\n");
//
//    do
//    {
//        system("cls");
//        if (ckey == '1')
//        {
//            system("cls");
//            InitList(&head);
//            goon();
//        }
//        else if (ckey == '2')
//        {
//            system("cls");
//            printf("请输入你想销毁的链表（L或者L2）。");
//            char C = 'a';
//            _getch();
//            if (C=='L')
//            {
//                DestroyList(&L);
//                goon();
//            }
//            else if (C=="L2")
//            {
//                DestroyList(&L2);
//                goon();
//            }
//            else
//            {
//                printf("输入错误，请重新开始。");
//                goon();
//            }
//
//        }
//
//
//    } while (ckey != "Esc");
//
//}
//
//void goon()
//{
//    printf("按任意键继续！！！");
//    _getch();
//}




