// #include <bits/stdc++.h>
// using namespace std;
// #define State void
// #define ElemType int
// #define SElemType int
// #define STACK_INIT_SIZE 100
// #define STACKINCREMENT 10
// //#define ERROR 0
// #define OK 1
// #define TRUE true
// #define FALSE false
// #include<bits/stdc++.h>
// #define OK 0
// #define ERROR -1
// typedef int State;
// typedef struct LinkList
// {
//     char operatorAndData;
//     struct LinkList *next;
// }LinkList,*LinkNode;
// typedef struct LinkStack
// {
//     LinkNode top;
//     int count;
// }LinkStack;


// /*利用链栈实现计算*/

// //创建链栈(栈是一个没有头结点的单链表)
// State createStack(LinkStack &S) {
//     S->count = -1;
//     S.Top = NULL;
//     return OK;
// }
// //push
// State pushStack(LinkStack &S, char data) {
//     LinkNode s;
//     s = (LinkNode)malloc(sizeof(LinkList));
//     s->operatorAndData = data;
//     s->next = S.Top;
//     S.Top = s;
//     S->count++;
//     return OK;
// }
// //pop
// State popStack(LinkStack &S,char *data) {
//     LinkNode p;
//     //判断栈空
//     if (S.Top == NULL || S->count==-1) {
//         return ERROR;
//     }
//     *data = S.Top->operatorAndData;
//     p = S.Top;
//     S.Top = S.Top->next;
//     S->count--;
//     free(p);
//     return OK;
// }
// //创建链表用于存储输入表达式
// int main() {
//     LinkStack infixExpression;
//     LinkStack computeStack;
//     int i = 0;
//     int j = 0;
//     char result;
//     State state;
//     char inExpression[50] = { 0 };
//     char postfixExpression[50] = { 0 };
//     char postTmp;
//     char operatorData1;
//     char operatorData2;
//     createStack(&infixExpression);
//     createStack(&computeStack);
//     gets(inExpression);

//     //中缀表达式转后缀表达式
//     while (inExpression[i]!='\0') {
//         if (inExpression[i]<48 || inExpression[i]>57) {
//             if (inExpression[i] == 41) {
//                 if (!(infixExpression.count < 0)) {
//                     popStack(&infixExpression, &postTmp);
//                     while (postTmp != 40) {
//                         postfixExpression[j++] = postTmp;
//                         if (!(infixExpression.count < 0))
//                             popStack(&infixExpression, &postTmp);
//                         else
//                             break;
//                     }
//                 }
//             }
//             else if (inExpression[i] == 43 || inExpression[i] == 45 ) {
//                 if (!(infixExpression.count < 0)) {
//                     popStack(&infixExpression, &postTmp);
//                     while (postTmp == 42 || postTmp == 47) {
//                         postfixExpression[j++] = postTmp;
//                         if (!(infixExpression.count < 0)) {
//                             popStack(&infixExpression, &postTmp);
//                         }
//                         else
//                             break;
//                     }
//                     pushStack(&infixExpression, postTmp);
//                 }
//                 pushStack(&infixExpression, inExpression[i]);
//             }
//             else {
//                 pushStack(&infixExpression, inExpression[i]);
//             }

//         }
//         else {
//             postfixExpression[j++] = inExpression[i];
//         }
//         i++;
//     }
//     while (!(infixExpression.count < 0)) {
//         popStack(&infixExpression, &postTmp);
//         postfixExpression[j++] = postTmp;
//     }
//     //计算后缀表达式
//     i = 0;
//     while (i != j) {
//         if (postfixExpression[i]<48 || postfixExpression[i]>57) {
//             popStack(&computeStack, &operatorData1);
//             popStack(&computeStack, &operatorData2);
//             if (postfixExpression[i] == 43) {
//                 postTmp = (operatorData2-48 + operatorData1-48)+48;
//                 pushStack(&computeStack, postTmp);
//             }

//             if (postfixExpression[i] == 45) {
//                 postTmp = (operatorData2 - 48) - 
//                     (operatorData1 - 48) + 48;
//                 pushStack(&computeStack, postTmp);
//             }
//             if (postfixExpression[i] == 42){
//                 postTmp = (operatorData2 - 48) *
//                     (operatorData1 - 48) + 48;
//                 pushStack(&computeStack, postTmp);
//             }
//             if (postfixExpression[i] == 47) {
//                 postTmp = (operatorData2 - 48) /
//                     (operatorData1 - 48) + 48;
//                 pushStack(&computeStack, postTmp);
//             }

//         }
//         else
//             pushStack(&computeStack, postfixExpression[i]);
//         i++;
//     }
//     popStack(&computeStack, &result);
//     printf("%c\n", result);
//     return OK;
// }

#include <bits/stdc++.h>
using namespace std;
#define Status int
#define ElemType int
#define SElemType char
#define CElemType char
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR 0
#define OK 1
#define TRUE true
#define FALSE false
#define OperandType 

typedef struct
{
    SElemType *Base;
    SElemType *Top;
    ElemType StackSize;
} SqStack;
SqStack S;
ElemType e;
ElemType ans;
CElemType str,ss,orz;


Status InitStack(SqStack &S)
{
    S.Base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.Base)
    {
        exit(OVERFLOW);
    }

    S.Top = S.Base;
    S.StackSize = STACK_INIT_SIZE;
    return OK;
} //Initialize Stack

Status Push(SqStack &S, CElemType e)
{
    if (S.Top - S.Base == S.StackSize)
    {
        S.Base = (SElemType *)realloc(S.Base, (S.StackSize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.Base)
        {
            exit(OVERFLOW);
        }
        S.Top = S.Base + S.StackSize;
        S.StackSize += STACKINCREMENT;
        return ERROR;
    }
    *(S.Top) = e;
    S.Top++;
    return OK;
}

ElemType Pop(SqStack &S, SElemType &e)
{
    if (S.Top == S.Base)
    {
        exit(OVERFLOW);
    }
	S.Top--;
    e = *(S.Top);
    return OK;
}

// CElemType GetTop(SqStack S){
//     if(S.Top!=S.Base){
//         ss= *(S.Top-1);
//         return ss;
//     }
//     else return ERROR;

// }
SElemType GetTop(SqStack S){
	if(S.Top!=S.Base)
	return *(S.Top-1);
    else return ERROR; 
}

bool StackEmpty(SqStack &S){
    return (S.Base != S.Top);
}

bool isOP(CElemType e){
    if(e=='+'||
        e=='-'||
        e=='*'||
        e=='/'||
        e=='('||
        e==')'||
        e=='#') return TRUE;
    else return FALSE;
}

CElemType Compare(CElemType a, CElemType b){
    if(a=='+'||a=='-'){
        if(b=='+'||b=='-'||b==')'||b=='#') return'>';
        else if(b=='*'||b=='/'||b=='(') return'<';
    }
    else if(a=='*'||a=='/'){
        if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#') return'>';
        else if(b=='(') return'<';
    }
    else if(a=='('){
        if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(') return'<';
		else if(b==')') return'=';
    }
    else if(a==')'){
        if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(') return'>';
    }
    else if(a=='#'){
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')  return'<';
	else if(b=='#') return'=';
	}
    return str;
}

CElemType Operate(CElemType x, CElemType y, CElemType OP){
	int a=x-48;int b=y-48;
	if(OP=='+')	return a+b+48;
	else if(OP=='-')	return a-b+48;
	else if(OP=='*') return a*b+48;
	else if(OP=='/')	return a/b+48;	  
	return str;
}

ElemType EvaluateExpression()
{
	SqStack OPND,OPTR;
	char ch,a,b,OP,x;
	InitStack(OPTR); Push(OPTR,'#');
	InitStack(OPND); ch=getchar();
    while(ch!='#'||GetTop(OPTR)!='#')
	{
		if(!isOP(ch))
		{
			Push(OPND,ch);
			ch=getchar();
		}
		else
		{
			switch(Compare(GetTop(OPTR),ch))
			{
				case '<':
					Push(OPTR,ch);
				    ch=getchar();
					break;
				case '>':
					Pop(OPTR,OP);
					Pop(OPND,b);
					Pop(OPND,a);
					Push(OPND,Operate(a,b,OP));
					break;
				case '=':
					Pop(OPTR,x);
				    ch=getchar();
					break;
			}
		} 
	}
	return GetTop(OPND)-48;
}
int main()
{
	printf("Input the Expression:\n");
	int ans=EvaluateExpression();
	printf("The answer is: %d\n",ans);
	return 0;
}
	






// Status conversion(SqStack &S, int e)
// {
//     while (e)
//     {
//         Push(S, e % 8);
//         e = e / 8;
//     }
//     while (S.Base != S.Top)
//     {
//         ans = Pop(S);
//         printf("%d", ans);
//     }
// }
// int main()
// {
//     // Status conversion(SqStack &S,int e);
//     scanf("%d", &e);
//     InitStack(&S);
//     conversion(&S, e);
// }