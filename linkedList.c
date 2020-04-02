#include "../head/linkedList.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value  只使用没有值的头节点初始化空链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {

    *L = (LinkedList)malloc(sizeof(LNode)); /*产生头节点，并使L指向此头节点*/
    if (!(*L)) {
        return ERROR;
    }
    (*L)->next = NULL;

    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes  销毁一个链表，释放所有节点
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {

    LinkedList q= (LinkedList)malloc(sizeof(LNode));
    LinkedList p= (LinkedList)malloc(sizeof(LNode));
    p = (*L)->next;           /*p指向第一个结点 */
    while (p)                 /*没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;        /* 头结点指针域为空 */

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p  在节点p之后插入节点q
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
 *	@description : delete the first node after the node p and assign its value to e  删除节点p之后的第一个节点，并将其值赋给e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {

    LNode* s = p->next;
    *e = s->data;  //对于这个语句，我实在不知道为什么会报异常，害
    p->next = s->next;
    free(s);
    return SUCCESS;

}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit  遍历链表并调用函数访问
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p =L;
    printf("list data is: ");
    while (p)
    {
        (*visit)(p->data);  /*运用回调函数*/
        p = p->next;
    }


}

void print_date(ElemType e) {
    printf("%d\t", e);
}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e  根据e找到链表中的第一个节点
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
    while (q)  /*通过遍历找到e*/
    {
        if (q->data == e)
        {
            printf("该数字在节点%d\n", a);
            return SUCCESS;
        }
        q = q->next;
        a++;
    }
    printf("不存在该数字");
    return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list  反转链表
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
 *	@description : judge whether the linked list is looped  判断链表是否循环
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    LinkedList pFast, pSlow;  //通过快慢指针来判断是否循环，因为如果循环的话，两个指针就会重叠在一起
    pFast = L;
    pSlow = L;
    while (1)
    {
        if (pSlow == NULL || pFast == NULL)
        {
            printf("这不是循环链表。");
            return ERROR;
        }
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast || pFast->next == pSlow)
        {
            printf("这是循环链表。");
                return SUCCESS;
        }
        printf("这不是循环链表。");
        return SUCCESS;
    }

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3  对链表中值为偶数的节点进行反向操作，输入:1 -> 2 -> 3 -> 4输出:2 -> 1 -> 4 -> 3
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
        t1->next = t2->next;    //运行时这一句报异常
        t2->next = t1;
        t = t1;
    }
    t = front->next;
    free(front);
    return t;


}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list  在链表中找到中间节点
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
    当前快指针走完链表时，慢指针刚好走到中间结点。
    当结点数是奇数时，慢指针走到中间结点，
    当结点数是偶数时，此时中间结点有2个，此时慢指针指向靠前那个结点。

    */
    return slow;

}

