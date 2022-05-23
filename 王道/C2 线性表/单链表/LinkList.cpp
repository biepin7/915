#include<stdio.h>

#define ElemType int 

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList &L){
    LNode *s,
    int x;
    L = new LNode;
    L->next = NULL;
    scanf("%d",&x);
    while(x！=9999){
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}
