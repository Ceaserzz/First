#include "../head/duLinkedList.h"
#include <stdlib.h>
# include <malloc.h>
#include <stdio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node  仅使用头节点初始化空链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    (*L)->prior = NULL;
    (*L)->next = NULL;
    (*L)->data = 0;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list  销毁一个链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {

        DuLinkedList p = (*L)->next;
        while (p)
        {
            DuLinkedList q = p->next;
            free(p);
            p = q;
        }
        (*L)->next = NULL;
        return SUCCESS;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p  在节点p之前插入节点q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : Nones
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    q->next = p;
    q->prior = p->prior;
    p->prior->next = q;
    p->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p  在节点p之后插入节点q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    q->next = p->next;
    p->next->prior = q;
    p->next = q;
    q->prior = p;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e  删除节点p之后的第一个节点，并将其值赋给e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLinkedList s = p->next;
    *e = s->data;
    p->next = s->next;
    s->next->prior = p;
    free(s);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit  遍历链表并调用函数访问
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList p = NULL;
    p = L->next;
    int i = 0;
    while (p)
    {
        (*visit)(p->data);
        p = p->next;
        i++;
    }
    if (i == 0)
    {
        printf("链表为空。");
    }
    return SUCCESS;

}

void print_date(ElemType e) {
    printf("%d\t", e);
}

//下列函数为创建双链表
void CreatList(DuLinkedList* L) {
    int x;
    (*L) = (DuLinkedList)malloc(sizeof(DuLNode));
    DuLNode* s, * p = *L;
    scanf_s("%d", &x);
    while (x != 999) {
        s = (DuLNode*)malloc(sizeof(DuLNode));
        s->data = x;
        p->next = s;
        s->prior = p;
        p = s;
        scanf_s("%d", &x);
    }
    p->next = NULL;
}