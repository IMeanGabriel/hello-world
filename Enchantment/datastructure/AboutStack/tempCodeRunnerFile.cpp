bool StackEmpty(SqStack &S)
{
    // if(S.StackSize == -1)
    //     return TRUE;
    // else
    //     return FALSE;
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