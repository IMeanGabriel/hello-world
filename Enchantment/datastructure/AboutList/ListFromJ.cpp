#include <bits/stdc++.h>
using namespace std;
#define LISTINCREMENT 10
#define LIST_INIT_SIZE 100
typedef int ElemType;
typedef void Status;

typedef struct L_Node
{
    ElemType elem;
    struct L_Node *next;
} L_Node, *L_List;

Status L_Input(L_List &L)
{
    ElemType e;
    L_List p = L;
    while (scanf("%d", &e) != EOF)
    {
        p->next = (L_Node *)malloc(sizeof(L_Node));
        p = p->next;
        p->elem = e;
        p->next = NULL;
    }
}
Status L_Initialize(L_List &L)
{
    L = (L_Node *)malloc(sizeof(L_Node));
    L->next = NULL;
}
Status L_InsertByIndex(L_List &L, ElemType i, ElemType &e)
{

    L_List p = L;
    ElemType cnt = 0;
    while (p && cnt < i - 1)
    {
        p = p->next;
        cnt++;
    }
    L_List q = (L_Node *)malloc(sizeof(L_Node));
    q->elem = e;
    q->next = p->next;
    p->next = q;
}

Status L_DeleteByIndex(L_List &L, ElemType i, ElemType &e)
{
    L_List p = L;
    ElemType cnt = 0;
    while (p->next && cnt < i - 1)
    {
        p = p->next;
        cnt++;
    }
    L_List q = p->next;
    e = q->elem;
    p->next = q->next;
    free(q);
}

Status L_Show(L_List &L)
{
    L_List p = L->next;
    while (p != 0)
    {
        printf("%d ", p->elem);
        p = p->next;
    }
    printf("\n");
}

Status L_Delete(L_List &L)
{
    free(L);
    L->next = 0;
    L->elem = 0;
}

int main()
{
    L_List a;
    L_Initialize(a);
    ElemType i, e;
    printf("Input all elements with a blank as an interval,input Ctrl + Z to stop:\n");

    L_Input(a);
    printf("Now the list looks like this: \n");
    L_Show(a);
    printf("Choose an element to insert : ");
    scanf("%d", &e);
    printf("Now choose an index to insert this element at : ");
    scanf("%d", &i);
    L_InsertByIndex(a, i, e);
    printf("Now the list looks like this: \n");
    L_Show(a);

    printf("Choose an index to delete : ");
    scanf("%d", &i);
    L_DeleteByIndex(a, i, e);
    printf("Now the list looks like this: \n");
    L_Show(a);
    L_Delete(a);
    return 0;
}
