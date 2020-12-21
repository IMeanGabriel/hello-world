#include <bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 100
#define STACKNCREMRNT 10

#define MAX_TREE_SIZE 100

//===============================================================================================
typedef int Status;
typedef char CElemType;
typedef int ElemType;


//int m,i,s1,s2;

// typedef struct BiTNode
// {
// 	CElemType Elem;
// 	struct BiTNode *lchild;
// 	struct BiTNode *rchild;
// } BiTNode, *BiTree;

// typedef struct
// {
// 	BiTree *Base;
// 	BiTree *Top;
// 	ElemType Stacksize;
// } SqStack;

//===============================================================================================
typedef struct{
    int weight;
    int parent, lchild,rchild;
}HTNode, *HuffmanTree;
typedef char * *HuffmanCode;

    int *w;
    int n;
    HuffmanTree HT;
    HuffmanCode HC;

    int m, i;
    HuffmanTree p;
    int s1, s2;
    char* cd;
    int start, c;
    unsigned int f;
//===============================================================================================



// typedef struct QNode
// {
// 	BiTree Elem;
// 	struct QNode *next;
// } QNode, *Qptr;

// typedef struct
// {
// 	Qptr front;
// 	Qptr rear;
// } LinkQueue;

//===============================================================================================
// Status InitStack(SqStack &S)
// {
// 	S.Base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTree));
// 	S.Top = S.Base;
// 	S.Stacksize = STACK_INIT_SIZE;
// 	return OK;
// }
// Status StackEmpty(SqStack S)
// {
// 	if (S.Top == S.Base)
// 		return TRUE;
// 	else
// 		return FALSE;
// }
// BiTree GetTop(SqStack S)
// {
// 	BiTree e;
// 	if (S.Top == S.Base)
// 		return ERROR;
// 	e = *(S.Top - 1);
// 	return e;
// }
// Status Push(SqStack &S, BiTree e)
// {
// 	if (S.Top - S.Base > S.Stacksize)
// 	{
// 		S.Base = (BiTree *)realloc(S.Base, (S.Stacksize + STACKNCREMRNT) * sizeof(BiTree));
// 		S.Top = S.Base + S.Stacksize;
// 	}
// 	*S.Top++ = e;
// 	return OK;
// }
// Status Pop(SqStack &S, BiTree e)
// {
// 	e = *--S.Top;
// 	return OK;
// }

// //===============================================================================================
// Status InitQueue(LinkQueue &Q)
// {
// 	Q.front = Q.rear = (Qptr)malloc(sizeof(BiTree));
// 	Q.front->next = NULL;
// 	return OK;
// }

// Status PushQueue(LinkQueue &Q, BiTree e)
// {
// 	Qptr p;
// 	p = (Qptr)malloc(sizeof(BiTree));
// 	if (!p)
// 		exit(OVERFLOW);
// 	p->Elem = e;
// 	p->next = NULL;
// 	Q.rear->next = p;
// 	Q.rear = p;
// 	return OK;
// }

// Status PopQueue(LinkQueue &Q, BiTree &e)
// {
// 	Qptr p;
// 	if (Q.front == Q.rear)
// 		return ERROR;
// 	p = Q.front->next;
// 	e = p->Elem;
// 	Q.front->next = p->next;
// 	if (Q.rear == p)
// 		Q.rear = Q.front;
// 	free(p);
// 	return OK;
// }
// Status QueueEmpty(LinkQueue Q)
// {
// 	if (Q.front == Q.rear)
// 		return TRUE;
// 	else
// 		return FALSE;
// }

// //===============================================================================================

// Status CreateBiTree(BiTree &T)
// {
// 	char ch;
// 	scanf("%c", &ch);
// 	if (ch == '#')
// 		T = NULL;
// 	else
// 	{
// 		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
// 			exit(OVERFLOW);
// 		T->Elem = ch;
// 		CreateBiTree(T->lchild);
// 		CreateBiTree(T->rchild);
// 	}
// 	return OK;
// }

// Status visit(CElemType e)
// {
// 	cout << e;
// 	return OK;
// }

// Status PreTraverse(BiTree T, Status (*visit)(CElemType))
// {
// 	if (T != NULL)
// 	{
// 		visit(T->Elem);
// 		if (PreTraverse(T->lchild, visit) && PreTraverse(T->rchild, visit))
// 			return OK;
// 		return ERROR;
// 	}
// 	else
// 		return OK;
// }
// Status PreOrderTraverse(BiTree T, Status (*visit)(CElemType))
// {
// 	SqStack S;
// 	BiTree p = T;
// 	InitStack(S);
// 	while (p != NULL || !StackEmpty(S))
// 	{
// 		if (p != NULL)
// 		{
// 			Push(S, p);
// 			visit(p->Elem);
// 			p = p->lchild;
// 		}
// 		else
// 		{
// 			Pop(S, p);
// 			p = *(S.Top);
// 			p = p->rchild;
// 		}
// 	}
// 	return OK;
// }

// Status InTraverse(BiTree T, Status (*visit)(CElemType))
// {
// 	SqStack S;
// 	BiTree p = T;
// 	InitStack(S);
// 	Push(S, T);
// 	while (!StackEmpty(S))
// 	{
// 		while (GetTop(S) && p != NULL)
// 		{
// 			p = *(S.Top - 1);
// 			Push(S, p->lchild);
// 		}
// 		Pop(S, p);
// 		if (!StackEmpty(S))
// 		{
// 			Pop(S, p);
// 			p = *(S.Top);
// 			visit(p->Elem);
// 			Push(S, p->rchild);
// 		}
// 	}
// 	return OK;
// }

// Status InOrderTraverse(BiTree T, Status (*visit)(CElemType))
// {
// 	SqStack S;
// 	InitStack(S);
// 	BiTree p = T;
// 	while (p != NULL || !StackEmpty(S))
// 	{
// 		if (p != NULL)
// 		{
// 			Push(S, p);
// 			p = p->lchild;
// 		}
// 		else
// 		{
// 			Pop(S, p);
// 			p = *(S.Top);
// 			visit(p->Elem);
// 			p = p->rchild;
// 		}
// 	}
// 	return OK;
// }

// Status PostTraverse(BiTree T, Status (*visit)(CElemType))
// {
// 	if (T != NULL)
// 	{
// 		if (PreTraverse(T->lchild, visit))
// 			if (PreTraverse(T->rchild, visit))
// 			{
// 				visit(T->Elem);
// 				return OK;
// 			}
// 		return ERROR;
// 	}
// 	else
// 		return OK;
// }

// void LayerTraverse(BiTree T, Status (*visit)(CElemType))
// {
// 	LinkQueue Q;
// 	BiTree p = T;
// 	if (T != NULL)
// 	{
// 		InitQueue(Q);
// 		PushQueue(Q, p);
// 		while (!QueueEmpty(Q))
// 		{
// 			PopQueue(Q, p);
// 			visit(p->Elem);
// 			if (p->lchild)
// 				PushQueue(Q, p->lchild);
// 			if (p->rchild)
// 				PushQueue(Q, p->rchild);
// 		}
// 	}
// }


//===============================================================================================


// void Select(HuffmanTree HT, int n, int *s1, int *s2) {
// 	int min = INT_MAX, semin = INT_MAX;
    
// 	for (int i = 1; i <= n; ++i) {
// 		if (HT[i].parent == 0 && HT[i].weight < min) {
// 			min = HT[i].weight;
// 			*s1 = i;
// 		}
// 	}
// 	HT[*s1].parent = 1;
// 	for (int i = 1; i <= n; ++i) {
// 		if (HT[i].parent == 0 && HT[i].weight < semin) {
// 			semin = HT[i].weight;
// 			*s2 = i;
// 			//HT[i].parent = 1;
// 		}
// 	}
// 	if(*s1>*s2) {
// 	    int j=*s1;
// 	    *s1=*s2;
// 	    *s2=j;
// 	 }
// }
void Select(HuffmanTree HT, int end, int* s1, int* s2) {
    int i;
    int w1, w2;
    
    w1 = w2 = INT_MAX;
    
    for(i = 1; i <= end; i++) {
        // 忽略已经加入树的结点
        if(HT[i].parent != 0) {
            continue;
        }
        
        if(HT[i].weight < w1) {
            *s2 = *s1;
            w2 = w1;
            
            *s1 = i;
            w1 = HT[i].weight;
        } else if(HT[i].weight >= w1 && HT[i].weight < w2) {
            *s2 = i;
            w2 = HT[i].weight;
        } else {
            // HT[i].weight>=w2
        }
    }
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
    if(n<=1)
        return;
    m=2*n-1;
    *HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    (*HT)[0].weight=n;
    
    for(p=(*HT)+1,i=1;i<=n;i++,p++)
        *p = { *w,0,0,0};
    for(; i<=m;i++,p++)
        *p={0,0,0,0};
    for(i=n+1;i<=m;i++){
        Select(*HT,i-1,&s1,&s2);
        (*HT)[s1].parent=i;
        (*HT)[s2].parent=i;
        (*HT)[i].lchild=s1;
        (*HT)[i].rchild=s2;
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
    }
    (*HC)=(HuffmanCode)malloc((n+1)*sizeof(char*));
    char * cd;
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1;i<=n;i++){
        int start=n-1;
        for(int c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent)
            if((*HT)[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
       (*HC)[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy((*HC)[i],&cd[start]);
    }
    free(cd);
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int x;
    int w[MAX_TREE_SIZE];
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&w[i]);
    }
    HuffmanCoding(HT,HC,w,x);
    for(int i=0;i<x;i++){
        printf("%d ",HC[i]);
    }
}
