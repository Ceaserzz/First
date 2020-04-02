#include "../head/linkedList.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value  ֻʹ��û��ֵ��ͷ�ڵ��ʼ��������
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {

    *L = (LinkedList)malloc(sizeof(LNode)); /*����ͷ�ڵ㣬��ʹLָ���ͷ�ڵ�*/
    if (!(*L)) {
        return ERROR;
    }
    (*L)->next = NULL;

    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes  ����һ�������ͷ����нڵ�
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {

    LinkedList q= (LinkedList)malloc(sizeof(LNode));
    LinkedList p= (LinkedList)malloc(sizeof(LNode));
    p = (*L)->next;           /*pָ���һ����� */
    while (p)                 /*û����β */
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;        /* ͷ���ָ����Ϊ�� */

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p  �ڽڵ�p֮�����ڵ�q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {

    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e  ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {

    LNode* s = p->next;
    *e = s->data;  //���������䣬��ʵ�ڲ�֪��Ϊʲô�ᱨ�쳣����
    p->next = s->next;
    free(s);
    return SUCCESS;

}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit  �����������ú�������
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p =L;
    printf("list data is: ");
    while (p)
    {
        (*visit)(p->data);  /*���ûص�����*/
        p = p->next;
    }


}

void print_date(ElemType e) {
    printf("%d\t", e);
}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e  ����e�ҵ������еĵ�һ���ڵ�
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    int a = 0;
    if (NULL == L)
    {
        return ERROR;
    }
    LinkedList q = L;
    while (q)  /*ͨ�������ҵ�e*/
    {
        if (q->data == e)
        {
            printf("�������ڽڵ�%d\n", a);
            return SUCCESS;
        }
        q = q->next;
        a++;
    }
    printf("�����ڸ�����");
    return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list  ��ת����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {

    LinkedList pNewHead = NULL;
    LinkedList pPrev = NULL;
    LinkedList pCur = (*L);
    while (pCur != NULL)
    {
        LinkedList pTmp = pCur->next;
        if (pTmp == NULL)
        {
            pNewHead = pCur;
        }
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = pTmp;
    }

    return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped  �ж������Ƿ�ѭ��
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    LinkedList pFast, pSlow;  //ͨ������ָ�����ж��Ƿ�ѭ������Ϊ���ѭ���Ļ�������ָ��ͻ��ص���һ��
    pFast = L;
    pSlow = L;
    while (1)
    {
        if (pSlow == NULL || pFast == NULL)
        {
            printf("�ⲻ��ѭ������");
            return ERROR;
        }
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast || pFast->next == pSlow)
        {
            printf("����ѭ������");
                return SUCCESS;
        }
        printf("�ⲻ��ѭ������");
        return SUCCESS;
    }

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3  ��������ֵΪż���Ľڵ���з������������:1 -> 2 -> 3 -> 4���:2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

    LinkedList  front = (LinkedList)malloc(sizeof(LNode));
    front->next = L;
    LinkedList t = front,  t1 = NULL,  t2 = NULL;
    while (t && t->next && t->next->next) {
        t1 = t->next;
        t2 = t1->next;
        t->next = t2;
        t1->next = t2->next;    //����ʱ��һ�䱨�쳣
        t2->next = t1;
        t = t1;
    }
    t = front->next;
    free(front);
    return t;


}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list  ���������ҵ��м�ڵ�
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

    LinkedList fast = (*L)->next;
    LinkedList slow = (*L)->next;

    while (fast->next != NULL)
    {

        if (fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        else
        {
            fast = fast->next;

        }
    }
    /*
    ��ǰ��ָ����������ʱ����ָ��պ��ߵ��м��㡣
    �������������ʱ����ָ���ߵ��м��㣬
    ���������ż��ʱ����ʱ�м�����2������ʱ��ָ��ָ��ǰ�Ǹ���㡣

    */
    return slow;

}

