#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int d;
    struct node *next;
}Node_Type;

Node_Type *HEAD;

/* 链表初始化 */
void InitLinkedList()
{
    HEAD = NULL;
}

/* 判断链表是否为空 */
int LinkedListStatus()
{
    if(HEAD == NULL)
        return 0;
    else
        return 1;
}

/* 扫描输出链表元素 */
void PrintLinkedList()
{
    Node_Type *p;
    p = HEAD;
    if(p == NULL)
        printf("  empty list!\n");
    else{
        printf("  链表元素: ");
        do{
            printf("%d ", p->d);
            p = p->next;
        }while(p != NULL);
        printf("\n");
    }
}

/* 尾插法建立单链表 */
void CreateLinkedList(int n)
{
    int i, x;
    Node_Type *p, *r;
    HEAD = NULL;
    r = NULL;
    printf("  请输入%d个整数: ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        p = (Node_Type *)malloc(sizeof(Node_Type));
        p->d = x;
        p->next = NULL;
        if(HEAD == NULL)
            HEAD = p;
        else
            r->next = p;
        r = p;
    }
}

/* 单链表逆置（遍历一趟实现）*/
void ReverseLinkedList()
{
    Node_Type *p, *q, *r;
    p = HEAD;   /* p 指向当前待逆置的节点 */
    q = NULL;    /* q 指向已经逆置部分的第一个节点 */

    while(p != NULL){
        r = p->next;    /* 保存后继节点 */
        p->next = q;    /* 当前节点指针反转 */
        q = p;          /* q 前移，指向新的已逆置链表头 */
        p = r;          /* p 前移，处理下一个节点 */
    }
    HEAD = q;    /* 头指针指向原链表最后一个节点 */
}

/* 释放链表 */
void DestroyLinkedList()
{
    Node_Type *p, *q;
    p = HEAD;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    HEAD = NULL;
}

int main()
{
    int n;

    printf("===== 链表综合应用编程：单链表逆置 =====\n\n");

    /* 初始化链表 */
    InitLinkedList();

    /* 建立单链表 */
    printf("请输入链表元素个数: ");
    scanf("%d", &n);

    /* 尾插法建立链表，保持输入顺序 */
    CreateLinkedList(n);

    printf("\n原始链表:\n");
    PrintLinkedList();

    /* 逆置链表（遍历一趟）*/
    ReverseLinkedList();

    printf("\n链表逆置后:\n");
    PrintLinkedList();

    /* 释放内存 */
    DestroyLinkedList();

    printf("\n===== 程序结束 =====\n");
    return 0;
}
