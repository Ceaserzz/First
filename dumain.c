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
    printf("����������Ԫ�أ�������999ʱֹͣ���롣");
    CreatList(&L);  //����˫����
    printf("\n--------------����Ϊ������˫����--------------\n");
    TraverseList_DuL(L,print_date);  //�����������ú�������
    printf("\n--------------����Ϊɾ�����ڶ����ڵ�󲢽�ֵ����num���������num--------------\n");
    DeleteList_DuL(L->next->next, &num);  //ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
    printf("num=%d\n", num);
    TraverseList_DuL(L, print_date);
    printf("\n--------------����Ϊ�ڵڶ����ڵ�ǰ����ڵ�n������--------------\n");
    InsertBeforeList_DuL(L->next->next, &n);
    TraverseList_DuL(L, print_date);
    printf("\n--------------����Ϊ��������--------------\n");
    DestroyList_DuL(&L);
    TraverseList_DuL(L, print_date);
}
//2���賿һ����ʮ��˯��˯��

