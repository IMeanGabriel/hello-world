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
// State createStack(LinkStack *S) {
//     S->count = -1;
//     S->top = NULL;
//     return OK;
// }
// //push
// State pushStack(LinkStack *S, char data) {
//     LinkNode s;
//     s = (LinkNode)malloc(sizeof(LinkList));
//     s->operatorAndData = data;
//     s->next = S->top;
//     S->top = s;
//     S->count++;
//     return OK;
// }
// //pop
// State popStack(LinkStack *S,char *data) {
//     LinkNode p;
//     //判断栈空
//     if (S->top == NULL || S->count==-1) {
//         return ERROR;
//     }
//     *data = S->top->operatorAndData;
//     p = S->top;
//     S->top = S->top->next;
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