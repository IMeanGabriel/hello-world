#include <bits/stdc++.h>
using namespace std;
#define Status void
#define ElemType int
#define SElemType int
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR 0
#define TRUE true
#define FALSE false

typedef struct
{
    SElemType *Base;
    SElemType *Top;
    ElemType StackSize;
} SqStack;

SqStack S;
ElemType e;
ElemType k;
ElemType ans;

Status InitStack(SqStack *s)
{
    s->Base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s->Base)
    {
        exit(OVERFLOW);
    }

    s->Top = s->Base;
    s->StackSize = STACK_INIT_SIZE;
} //Initialize Stack

Status Push(SqStack *S, SElemType e)
{
    if (S->Top - S->Base >= S->StackSize)
    {
        S->Base = (SElemType *)realloc(S->Base, (S->StackSize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->Base)
        {
            exit(OVERFLOW);
        }
        S->Top = S->Base + S->StackSize;
        S->StackSize += STACKINCREMENT;
    }
    *(S->Top) = e;
    S->Top++;
}

ElemType Pop(SqStack *S)
{
    if (S->Top == S->Base)
    {
        exit(OVERFLOW);
    }
    e = *--(S->Top);
    return e;
}

bool StackEmpty(SqStack *S)
{
    // if(S->StackSize == -1)
    //     return TRUE;
    // else
    //     return FALSE;
    return (S->Base != S->Top);
}

Status conversion(SqStack *S, int e, int k)
{
    while (e)
    {
        Push(S, e % k);
        e = e / k;
    }
    while (S->Base != S->Top)
    {
        ans = Pop(S);
        printf("%d", ans);
    }
}
int main()
{
    // Status conversion(SqStack *S,int e);
    for(int i=1;i<=5;i++){
        printf("\nInput the decimal number you want to converse: ");
    scanf("%d", &e);
    printf("Input the radix you want to converse into: ");
    scanf("%d",&k);
    InitStack(&S);
    printf("The answer is: ");
    conversion(&S, e, k);
    }
}

