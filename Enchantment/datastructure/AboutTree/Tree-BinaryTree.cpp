// #include<stdio.h>
// #include<stdlib.h>

// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
// #define INFEASIBLE -1
// #define OVERFLOW -2
// #define STACK_INIT_SIZE 100//栈的初始空间 
// #define STACKNCREMRNT 10//栈的增加量 

// #define MAX_TREE_SIZE 100//二叉树的最大结点

// typedef int Status;
// typedef char CElemType;
// typedef int QElemType;
 
// typedef struct BiTNode {
// 	CElemType Elem;
// 	struct BiTNode *lchild,*rchild;//左右孩子指针
// } BiTNode,*BiTree;

// typedef struct {
// 	BiTree *Base;//在构造栈前和销毁栈后,Base的值为NULL
// 	BiTree *Top;//栈顶指针
// 	int Stacksize;//当前分配的元素空间以元素为单位
// } SqStack;

// typedef struct QNode {
// 	BiTree Elem;
// 	struct QNode *next;
// } QNode,*Qptr;

// typedef struct {
// 	Qptr front;
// 	Qptr rear;
// } LinkQueue;

// //构造空栈
// Status InitStack(SqStack &S) {
// 	S.Base=(BiTree*)malloc(STACK_INIT_SIZE*sizeof(BiTree));
// 	if(!S.Base)exit(OVERFLOW);//储存分配失败
// 	S.Top=S.Base;
// 	S.Stacksize=STACK_INIT_SIZE;
// 	return OK;
// }





// //判断是否栈空
// Status StackEmpty(SqStack S) {
// 	if(S.Top==S.Base)return TRUE;
// 	else return FALSE;
// }
// //若栈不空，用e返回S的栈顶元素
// BiTree GetTop(SqStack S) {
// 	BiTree e;
// 	if(S.Top==S.Base)return ERROR;
// 	e=*(S.Top-1);
// 	return e;
// }
// //为栈插入新的栈顶元素e
// Status Push(SqStack &S,BiTree e) {
// 	if(S.Top-S.Base>S.Stacksize) {
// 		S.Base=(BiTree *)realloc(S.Base,(S.Stacksize+STACKNCREMRNT)*sizeof(BiTree));
// 		if(!S.Base)exit(OVERFLOW);//储存分配失败
// 		S.Top=S.Base+S.Stacksize;
// 	}
// 	*S.Top++=e;
// 	return OK;
// }
// //若栈不空，则删除栈顶元素，用e返回其值，返回OK，否则返回ERROR
// Status Pop(SqStack &S,BiTree e) {
// 	if(S.Top==S.Base)return ERROR;
// 	e=*--S.Top;
// 	return OK;
// }






// //构造一个空队列
// Status InitQueue(LinkQueue &Q) {
// 	Q.front=Q.rear=(Qptr)malloc(sizeof(BiTree));
// 	if(!Q.front)exit(OVERFLOW);//储存分配失败
// 	Q.front->next=NULL;
// 	return OK;
// }
// //插入元素e为Q的新队列
// Status EnQueue(LinkQueue &Q,BiTree e) {
// 	Qptr p;
// 	p=(Qptr)malloc(sizeof(BiTree));
// 	if(!p)exit(OVERFLOW);
// 	p->Elem=e;
// 	p->next=NULL;
// 	Q.rear->next=p;
// 	Q.rear=p;
// 	return OK;
// }
// //若队列头不空，删除Q的队头元素
// Status DeQueue(LinkQueue &Q,BiTree &e) {
// 	Qptr p;
// 	if(Q.front==Q.rear)return ERROR;
// 	p=Q.front->next;
// 	e=p->Elem;
// 	Q.front->next=p->next;
// 	if(Q.rear==p)Q.rear=Q.front;
// 	free(p);
// 	return OK;
// }
// //判断是否队列为空
// Status QueueEmpty(LinkQueue Q){
// 	if(Q.front==Q.rear)return TRUE;
// 	else return FALSE;
// } 


// Status visit(CElemType e) {
// 	printf("%c",e);
// 	return OK;
// }



// //按照先序次序输入二叉树结点的值(一个字符),空格表示空树,构造二叉链表标识的二叉树T
// Status CreateBiTree(BiTree &T) {
// 	char ch;
// 	scanf("%c",&ch);
// 	if(ch == '#') T = NULL;
// 	else {
// 		T=(BiTNode *)malloc(sizeof(BiTNode));
// 		if(!T) exit(OVERFLOW);
// 		T->Elem = ch;
// 		CreateBiTree(T->lchild);
// 		CreateBiTree(T->rchild);
// 	}
// 	return OK;
// }





// //先序递归
// Status PreTraverse(BiTree T,Status(*visit)(CElemType)) {
// 	if(T) {
// 		visit(T->Elem);
// 		if(PreTraverse(T->lchild,visit))
// 			if(PreTraverse(T->rchild,visit)) return OK;
// 		return ERROR;
// 	} else return OK;
// }
// //先序非递归
// Status PreOrderTraverse(BiTree T,Status(*visit)(CElemType)) {
// 	SqStack S;
// 	BiTree p=T;
// 	InitStack(S);
// 	while(p||!StackEmpty(S)) {
// 		if(p) { //向左走到尽头
// 			Push(S,p);//进栈
// 			visit(p->Elem);
// 			p=p->lchild;
// 		} else {
// 			Pop(S,p);
// 			p=*(S.Top);
// 			p=p->rchild;
// 		}
// 	}
// 	return OK;
// }






// //中序递归
// Status InTraverse(BiTree T,Status(*visit)(CElemType)) {
// 	SqStack S;
// 	BiTree p=T;
// 	InitStack(S);
// 	Push(S,T);//根指针进栈
// 	while(!StackEmpty(S)) {
// 		while(GetTop(S)&&p) {
// 			p=*(S.Top-1);
// 			Push(S,p->lchild);
// 		}//向左走到尽头
// 		Pop(S,p);//空指针退栈
// 		if(!StackEmpty(S)) {//访问结点，向右一步
// 			Pop(S,p);
// 			p=*(S.Top);
// 			visit(p->Elem);
// 			Push(S,p->rchild);
// 		}
// 	}
// 	return OK;
// }
// //中序非递归
// Status InOrderTraverse(BiTree T,Status(*visit)(CElemType)) {
// 	SqStack S;
// 	InitStack(S);
// 	BiTree p=T;
// 	while(p||!StackEmpty(S)) {
// 		if(p) { //根指针进栈，遍历左子树
// 			Push(S,p);
// 			p=p->lchild;
// 		} else { //根指针退栈，访问根结点，遍历右子树
// 			Pop(S,p);
// 			p=*(S.Top);
// 			visit(p->Elem);
// 			p=p->rchild;
// 		}
// 	}
// 	return OK;
// }






// //后续递归
// Status PostTraverse(BiTree T,Status(*visit)(CElemType)) {
// 	if(T) {
// 		if(PreTraverse(T->lchild,visit))
// 			if(PreTraverse(T->rchild,visit)) {
// 				visit(T->Elem);
// 				return OK;
// 			}
// 		return ERROR;
// 	} else return OK;
// }






// //层序遍历
// void LayerTraverse(BiTree T,Status(*visit)(CElemType)) {
// 	LinkQueue Q;
// 	BiTree p=T;
// 	if(T) {
// 		InitQueue(Q);
// 		EnQueue(Q,p);
// 		while(!QueueEmpty(Q)) {
// 			DeQueue(Q,p);
// 			visit(p->Elem);
// 			if(p->lchild!=NULL) EnQueue(Q,p->lchild);
// 			if(p->rchild!=NULL) EnQueue(Q,p->rchild);
// 		}
// 	}
// }





// //ABC##DE#G##F###
// int main() {
// 	BiTree T;
// 	CreateBiTree(T);
// 	printf("\n");

// 	PreTraverse(T,visit);
// 	printf("\n");
// 	PreOrderTraverse(T,visit);
// 	printf("\n");
// 	InTraverse(T,visit);
// 	printf("\n");
// 	InOrderTraverse(T,visit);
// 	printf("\n");
// 	PostTraverse(T,visit);
// 	printf("\n");
// 	//_PostTraverse(T,visit);
// 	LayerTraverse(T,visit);
// 	printf("\n");
// }

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

typedef struct BiTNode
{
	CElemType Elem;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct
{
	BiTree *Base;
	BiTree *Top;
	ElemType Stacksize;
} SqStack;

typedef struct QNode
{
	BiTree Elem;
	struct QNode *next;
} QNode, *Qptr;

typedef struct
{
	Qptr front;
	Qptr rear;
} LinkQueue;

//===============================================================================================
Status InitStack(SqStack &S)
{
	S.Base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTree));
	S.Top = S.Base;
	S.Stacksize = STACK_INIT_SIZE;
	return OK;
}
Status StackEmpty(SqStack S)
{
	if (S.Top == S.Base)
		return TRUE;
	else
		return FALSE;
}
BiTree GetTop(SqStack S)
{
	BiTree e;
	if (S.Top == S.Base)
		return ERROR;
	e = *(S.Top - 1);
	return e;
}
Status Push(SqStack &S, BiTree e)
{
	if (S.Top - S.Base > S.Stacksize)
	{
		S.Base = (BiTree *)realloc(S.Base, (S.Stacksize + STACKNCREMRNT) * sizeof(BiTree));
		S.Top = S.Base + S.Stacksize;
	}
	*S.Top++ = e;
	return OK;
}
Status Pop(SqStack &S, BiTree e)
{
	e = *--S.Top;
	return OK;
}

//===============================================================================================
Status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (Qptr)malloc(sizeof(BiTree));
	Q.front->next = NULL;
	return OK;
}

Status PushQueue(LinkQueue &Q, BiTree e)
{
	Qptr p;
	p = (Qptr)malloc(sizeof(BiTree));
	if (!p)
		exit(OVERFLOW);
	p->Elem = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status PopQueue(LinkQueue &Q, BiTree &e)
{
	Qptr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->Elem;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//===============================================================================================

Status CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->Elem = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status visit(CElemType e)
{
	cout << e;
	return OK;
}

Status PreTraverse(BiTree T, Status (*visit)(CElemType))
{
	if (T != NULL)
	{
		visit(T->Elem);
		if (PreTraverse(T->lchild, visit) && PreTraverse(T->rchild, visit))
			return OK;
		return ERROR;
	}
	else
		return OK;
}
Status PreOrderTraverse(BiTree T, Status (*visit)(CElemType))
{
	SqStack S;
	BiTree p = T;
	InitStack(S);
	while (p != NULL || !StackEmpty(S))
	{
		if (p != NULL)
		{
			Push(S, p);
			visit(p->Elem);
			p = p->lchild;
		}
		else
		{
			Pop(S, p);
			p = *(S.Top);
			p = p->rchild;
		}
	}
	return OK;
}

Status InTraverse(BiTree T, Status (*visit)(CElemType))
{
	SqStack S;
	BiTree p = T;
	InitStack(S);
	Push(S, T);
	while (!StackEmpty(S))
	{
		while (GetTop(S) && p != NULL)
		{
			p = *(S.Top - 1);
			Push(S, p->lchild);
		}
		Pop(S, p);
		if (!StackEmpty(S))
		{
			Pop(S, p);
			p = *(S.Top);
			visit(p->Elem);
			Push(S, p->rchild);
		}
	}
	return OK;
}

Status InOrderTraverse(BiTree T, Status (*visit)(CElemType))
{
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p != NULL || !StackEmpty(S))
	{
		if (p != NULL)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			Pop(S, p);
			p = *(S.Top);
			visit(p->Elem);
			p = p->rchild;
		}
	}
	return OK;
}

Status PostTraverse(BiTree T, Status (*visit)(CElemType))
{
	if (T != NULL)
	{
		if (PreTraverse(T->lchild, visit))
			if (PreTraverse(T->rchild, visit))
			{
				visit(T->Elem);
				return OK;
			}
		return ERROR;
	}
	else
		return OK;
}

void LayerTraverse(BiTree T, Status (*visit)(CElemType))
{
	LinkQueue Q;
	BiTree p = T;
	if (T != NULL)
	{
		InitQueue(Q);
		PushQueue(Q, p);
		while (!QueueEmpty(Q))
		{
			PopQueue(Q, p);
			visit(p->Elem);
			if (p->lchild)
				PushQueue(Q, p->lchild);
			if (p->rchild)
				PushQueue(Q, p->rchild);
		}
	}
}

int main()
{
	BiTree Trree;
	CreateBiTree(Trree);

	cout << "1.PreTravers Sequence (Recurrent): ";
	PreTraverse(Trree, visit);
	cout << endl
		 << "2.PreTravers Sequence (Non-Recurrent): ";
	PreOrderTraverse(Trree, visit);
	cout << endl
		 << "3.InTravers Sequence (Recurrent): ";
	InTraverse(Trree, visit);
	cout << endl
		 << "4.InTravers Sequence (Recurrent): ";
	InOrderTraverse(Trree, visit);
	cout << endl
		 << "5.PostTravers Sequence (Recurrent): ";
	PostTraverse(Trree, visit);
	cout << endl
		 << "6.PostTravers Sequence (Recurrent): ";
	LayerTraverse(Trree, visit);
}
