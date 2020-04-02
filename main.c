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
    printf("������������ĸ���(дһ���͹��˹�������Ĳ����Ҿ�����һ������)��");

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
    LinkedList head;  //��ͷ�ڵ�
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
    InitList(&head);                             //���Ժ���ֻʹ��û��ֵ��ͷ�ڵ��ʼ��������
    printf("\n----------------------------\n");
    InsertList(L->next->next, &Node1);
    TraverseList(L, print_date);                 //���Ա����������ú���
    printf("\n----------------------------\n");
    //printf("%d", num);
    //DeleteList(&L, &num);                      //����ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
    //printf("%d", num);                         //�ܷ�������ʱ���쳣��Ҳ��֪��������
    printf("\n----------------------------\n");
    printf("��������Ҫ���ҵ�����");
    int num2;
    scanf_s("%d", &num2);
    SearchList(L, num2);                       //���Ը���e�ҵ������еĵ�һ���ڵ�
    printf("\n----------------------------\n");
    //ReverseList(&L);                           //���Է�ת����
    //TraverseList(L, print_date);               //���Թ���ʼ�ղ��У�һֱ���ǰ��������ٳ�ֻ��ͷ�ڵ�
    printf("\n----------------------------\n");
    IsLoopList(L);                               //�����Ƿ�Ϊѭ������
    printf("\n----------------------------\n");
/*    ReverseEvenList(&L);                         //���Զ�������ֵΪż���Ľڵ���з������
    TraverseList(L, print_date);   */              //�ܲ��ң�����ʱ���쳣���Ҿ�����Ҫ��˼ѧϰ��������==
    printf("\n----------------------------\n");
    head = FindMidNode(&L);                        //����Ѱ���м�ڵ㣬�����һ�������������ǶԵ���
    printf("%d", head->data);                      //����
    printf("\n----------------------------\n");
    //DestroyList(&L);                               //���Ժ�������һ�������ͷ����нڵ�
    //TraverseList(L, print_date);                   //���ź���û��Բ����β�����е�����ʱ��˵������һ���ϵ㣬�������±�
    getchar();
    //����һ��������4��2���賿һ����ʮ��������ô����ҹ�������Ǹ㶨����ҵ���������һ�Ѳ�֪����ô�޸ĵĴ�ģ��Ѷ����������ݽṹ���治���ף����ǵü������ͣ���
}


LinkedList CreateSgLinkList(void)
{
    int i, length, data;
    LinkedList p_new = NULL, pTail = NULL;
    //����ͷ�ڵ㣬ͷ����ǵ�0���ڵ㣬����Ľڵ��1��ʼ����
    LinkedList pHead = (LinkedList)malloc(sizeof(LNode));

    if (NULL == pHead)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    pHead->data = 0;
    pHead->next = NULL;
    pTail = pHead;

    printf("������Ҫ��������ĳ��ȣ�");
    scanf_s("%d", &length);

    for (i = 1; i < length + 1; i++)
    {
        p_new = (LinkedList)malloc(sizeof(LNode));
        if (NULL == p_new)
        {
            printf("�ڴ����ʧ�ܣ�\n");
            exit(EXIT_FAILURE);
        }

        printf("�������%d���ڵ��ֵ��", i);
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
//    printf("������������Ϊ10�������Լ�һ������һ��ͷ���������ڵ㣬����Զ����������²�����\n");
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
//    printf("1.ʹ��û��ֵ��ͷ�ڵ��ʼ��������\n");
//    printf("2.����һ�������ͷ����нڵ�\n");
//    printf("3.�ڽڵ�p֮�����ڵ�q\n");
//    printf("4.ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e\n");
//    printf("5.����������ӡ\n");
//    printf("6.����e�ҵ������еĵ�һ���ڵ�\n");
//    printf("7.��ת����\n");
//    printf("8.�ж������Ƿ�ѭ��\n");
//    printf("9.��������ֵΪż���Ľڵ���з������������:1 -> 2 -> 3 -> 4���:2 -> 1 -> 4 -> 3\n");
//    printf("10.���������ҵ��м�ڵ�\n");
//    printf("\n----------------------------\n");
//    printf("��ESC�˳�����\n");
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
//            printf("�������������ٵ�����L����L2����");
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
//                printf("������������¿�ʼ��");
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
//    printf("�����������������");
//    _getch();
//}




