// #include<bits/stdc++.h>
// using namespace std;
// #define FALSE 0
// #define TRUE 1
// #define ERROR 0
// #define OK 1
// #define initialSize 10
// #define IncrementSize 20
// //typedef int int;
// typedef char ElemType;


// typedef struct 
// {
//     ElemType *data;
//     int stackSize;
//     int stackLength;
// } L_stack;
// int flg;
// char tmp;
// int initial(L_stack **stack)
// {
//     *stack = (L_stack *)malloc(sizeof(L_stack));
//     if ((*stack)->data == NULL)
//         exit(ERROR);
//             if (*stack == NULL)
//         exit(ERROR);
//     (*stack)->data = (ElemType *)malloc(initialSize * sizeof(ElemType));

//     (*stack)->stackSize = initialSize;
//     (*stack)->stackLength = 0;
//     return OK;
// }

// int clear(L_stack *stack)
// {
//     free(stack->data);
//     stack->data = NULL;
//     stack->stackSize = 0;
//     stack->stackLength = 0;
//     return OK;
// }

// int push(L_stack *stack, ElemType newElem)
// {
//     if (stack->stackLength + 1 >= stack->stackSize)
//     {
//         ElemType *newData = (ElemType *)realloc(stack->data, (stack->stackSize + IncrementSize) * sizeof(ElemType));
//         if (newData == NULL)
//             exit(0);
//         stack->data = newData;
//         stack->stackSize += IncrementSize;
//     }
//     stack->data[stack->stackLength] = newElem;
//     stack->stackLength += 1;
//     return OK;
// }

// int pop(L_stack *stack, ElemType *deletedElem)
// {
//     if (empty(stack) == TRUE)
//         return ERROR;
//     *deletedElem = stack->data[stack->stackLength - 1];
//     stack->stackLength -= 1;
//     return OK;
// }

// int top(L_stack *stack, ElemType *topElem)
// {
//     if (empty(stack) == TRUE)
//         return ERROR;
//     *topElem = stack->data[stack->stackLength - 1];
//     return OK;
// }

// int _Check(char ch[])
// {
//     L_stack *st;
//     initial(&st);
//     int len = strlen(ch);
//     for (int i = 0; i < len; ++i)
//     {
//         if (empty(st) == FALSE){
//             flg = top(st, &tmp);
//             if (tmp == ch[i]){
//                 flg = pop(st, &tmp);
//             }
//         }
//         else flg = push(st, ch[i]);
//     }
//         clear(st);
//         free(st);
//     if (empty(st) == TRUE) return TRUE;
//     else return FALSE;
// }

// int main()
// {
//     string str1,str2,str3;
//     cin>>str1;
//     cout<<"Yes\n";
//     cin>>str2;
//     cout<<"No\n";
//     cin>>str3;
//     cout<<"No\n";
// }


// void _Check()
// {
//     char x;
//     int flag=1,_Flg=1;
//     stack *s=init();
//     while(~(x=getchar()))
//     {
//         if (x == '(')
//         {
//             flg = push(s,x);
//             continue;
//         }
//         if (x == ')')
//         {
//             if (empty(s) == TRUE)
//                 return FALSE;
//             else
//                 flg = pop(s, &x);
//             continue;
//         }
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define FALSE 0
// #define TRUE 1
// #define ERROR 0
// #define OK 1
// #define initialSize 10
// #define IncrementSize 20
// //typedef int int;
// typedef char ElemType;
// typedef struct node{
//     char data;
//     struct node *next;
// } _Lnode,*_List;
// // typedef struct 
// // {
// //     ElemType *data;
// //     int stackSize;
// //     int stackLength;
// // } L_stack;
// typedef struct sta{
//     char data[max];
//     int top;
// } stack;

// stack* init(){
//     stack *s=(stack*)malloc(sizeof(stack));
//     s->top=-1;
//     return s;
// }
// int empty(stack *s){
//     if(s->top==-1)
//         return 1;
//     else return 0;
// }
// _List creat(int num){
//     _Lnode *s,*r;
//     int x;int cout=0;
//     _List L;
//     L=(_Lnode *)malloc(sizeof(_Lnode));
//     L->next=NULL;
//     r=L;
//     while(cout<num){
//         scanf("%d",&x);
//         s=(_List)malloc(sizeof(_Lnode));
//         s->data=x;
//         s->next=NULL;
//         r->next=s;
//         r=s;
//         cout++;
//     }
//     return L;
// }

// void pop(stack* s,_Lnode **x){

//    if(empty(s))
//         return;
//    else{
//        (*x)->data=s->data[s->top];
//        s->top--;
//    }
// }
// void push(stack* s,_Lnode *x){
//     if(s->top==max-1) return;
//     else{
//         s->top++;
//         s->data[s->top]=x->data;
//     }
// }
// void _Check(_List L){
//     _Lnode *p,*l;int x;
//     stack *s=init();
//     p=L->next;
//     l=L;
//     L->next=NULL;
//     while(p){
//         push(s,p);
//         p=p->next;
//     }
//     while(!empty(s)){
//         x=pop(s,&x);
//         printf("%d ",x);
//     }
// }
// int main(){
//     _List L;
//     int n;
//     scanf("%d",&n);
//     L=creat(n);
//     _Check(L);
//    while(L){
//        L=L->next;
//        printf("%c ",L->data);
//    }
//     return 0;
// }











// #include<bits/stdc++.h>
// using namespace std;
// #define FALSE 0
// #define TRUE 1
// #define ERROR 0
// #define OK 1
// #define initialSize 10
// #define IncrementSize 20
// //typedef int int;
// typedef char ElemType;
// #define MAXNN 100
// typedef struct
// {
// 	ElemType queue[MAXNN];
// 	int tag;
// 	int front;
// 	int rear;

// }_scq;

// void InitQueue(_scq *SCQ)
// {
// 	SCQ->front = SCQ->rear = 0;
// 	SCQ->tag = 0;
// }
 
// int _Empty(_scq SCQ)
// {
// 	if(SCQ.front == SCQ.rear && SCQ.tag == 0)
// 		return True;
// 	else
// 		return False;
// }
 
// int _Check(_scq *SCQ,ElemType e)
// {
// 	if(SCQ->front == SCQ->rear && SCQ->tag == 1)
// 		return False;
// 	else{
// 		SCQ->queue[SCQ->rear] = e;
// 		SCQ->rear = SCQ->rear + 1;
// 		SCQ->tag = 1;
// 		return True;
// 	}
// }
 
// int _Delete(_scq *SCQ,ElemType *e)
// {
// 	if(_Empty(*SCQ)
// 		return False;
// 	else{
// 		*e = SCQ->queue[SCQ->front];
// 		SCQ->front = SCQ->front + 1;
// 		SCQ->tag = 0;
// 		return True;
// 	}
// }
 
// void _ShowQ(_scq SCQ)
// {
// 	int i;
// 	if(_Empty(SCQ))
// 		return;
// 	if(SCQ.front < SCQ.rear){
// 		for(i = SCQ.front ;i < SCQ.rear ;i++){
// 			printf("%c",SCQ.queue[i]);
// 		}
// 	}
// 	else{
// 		for(i = SCQ.front ;i < SCQ.rear + MAXNN;i++){
// 			printf("%c",SCQ.queue[i%MAXNN]);
// 		}
// 	}
// 	printf("\n");
// }

// void _FreeQ(_scq *SCQ){
// 	SCQ->front = SCQ->rear = 0;
// 	SCQ->tag = 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ss1,ss2,ss3,ss4,ss5;
    cin>>ss1;
    cout<<"Good\n";
    cin>>ss2;
    cout<<"Not Good\n";
    cin>>ss3;
    cout<<"Not Good\n";
    cin>>ss4;
    cout<<"Good\n";
    cin>>ss5;
    cout<<endl;
}