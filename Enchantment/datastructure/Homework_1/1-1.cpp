#include<bits/stdc++.h>
using namespace std;
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OK 1
#define InitSize 10
#define IncrementSize 20
//typedef int Status;
typedef int ElemType;

typedef struct _List
{
    struct _List* elm;
    ElemType data;

}_List;

_List* Merging(_List* a, _List* b){

    _List* p1 = a;
    _List* p2 = b;
    _List* ans = (_List*)malloc(sizeof(_List));
    _List* p3 = ans;
    while (p1 != NULL && p2 != NULL){
        if (p1 == NULL){
            p3.elm = p2;
            p2 = p2.elm;
        }
        else if (p2 == NULL){
            p3.elm = p1;
            p1 = p1.elm;
            }
        else{
            if (p1.data <= p2.data){
                p3.elm = p1;
                p1 = p1.elm;
            }
            else{
                p3.elm = p2;
                p2 = p2.elm;
            }
        }
    }
    return ans;
}

void Delete(_List *start, _List *s) 
{
    _List *p,*q;
    p = start;q = start;
    while (p->next->next!=s)
        p = p->next;
    while (q->next != s)
        q = q->next;
    p->next = q->next;
    delete q;
}


void Insert( ElemType A[],ElemType x)
{
    int pos = 1;
    int n;
    while (A[pos] < e && pos <= n) pos++;
    for (int i = n; i >= pos; --i)
        A[i + 1] = A[i];
    A[pos] = x;
    n++;

}






void InverseList(ElemType &L,int iStart,int iEnd) { 
    ElemType *p, *q, temp ; 
    for (p = L.elem+iStart-1, q = L.elem + iEnd - 1; p < q; p ++,q --){ 
        temp = *p ; *p = *q ; *q = temp ; 
        } 
    } 

Status OrderInsert(ElemType A[], int &elenum, ElemType x) {   
    if (elenum>= sizeofList) 
        return ERROR;  //如果溢出   
    for(i=0; i<elenum && A[i]<x; i++); //找插入位置   
    for(j=elenum-1; j>=i; j--)     
        A[j+1] = A[j];  //将数据元素后移   
    A[i] = x;   
    elenum++;   
    return OK;


4、 void OrderInsert(_List L, ElemType x) { pre = L; 
// 指向待插入位置的前驱 p = L->next; // 指向待插入位置 while ( p && p->data < x) //查找插入位置 { pre = p; p = p->next; } s = (LNode *)malloc(sizeof(LNode)); //分配内存 if (!s) return; //失败返回 s->data = x; //给结点赋值 s->next = p; pre->next = s; //插入结点


void elemSwap(ElemType* a, ElemType* b)
{
    ElemType tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void listReverse(ElemType* L, int sizeofList)
{
    for (int i = 1; i <= sizeofList / 2; ++i)
    {
        elemSwap(L+i, L+sizeofList-i+1);
    }
}

void change(ElemType* L, int m, int n)
{
    listReverse(L, m + n);
    listReverse(L, n);
    listReverse(L + n, m);
}

void Judge(_List * head, int max, int min)
{ 
    _List * p, * q;
    if (head! =NULL){
        q = head;
        p= head-＞next;
    }
    while((p! =NULL) && (p-＞data＜=min){ 
        q=p;
        p=p-＞next;
    }
    while((p! =NULL) && (p-＞data＜max)){}
        p = p-＞next;
        q-＞next = p ;
}


int 

ElemType ListLength(_List*L)
{
    int len=0;
    _List *p;p=L;
    while(p-＞next!=NULL){
        p=p-＞next;
        len++;
    }
    return len;
}