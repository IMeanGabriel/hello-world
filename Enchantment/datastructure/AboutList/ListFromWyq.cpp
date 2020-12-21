/***********************************
               实验用头文件
               环境：C
               编译器：GCC
***********************************/
#ifdef DataStructure_Practice
#   ifndef DataStructure_Object
#       include <stdio.h>
#       include <stdlib.h>
#       include <stdbool.h>
#       include <string.h>
#   endif

#   ifdef DataStructure_Object
#       include <iostream>
#       include <string>
#   endif

#   define TRUE 1
#   define FALSE 0
#   define OK 1
#   define ERROR 0
#   define INFEASIBLE -1
#   define OVERFLOW -2

     typedef int Status;
#   ifndef DataStructure_Work
#   ifndef DataStructure_Object
        typedef int ElemType;
#   endif
#   endif

#   ifdef DataStructure_Linear
#       define InitSize 100
#       define IncrementSize 10
#   endif

#   ifdef DataStructure_Matrix
#       define MaxSize 12500
#   endif
#endif



/***********************************
         实验一 线性表（顺序实现）
***********************************/
#define DataStructure_Practice
#define DataStructure_Linear
typedef struct LinearList
{
    ElemType *data;
    int listSize;
    int listLength;
} LinearList;

void show(LinearList *list)
{
    for (int i = 0; i < list->listLength; ++i)
        printf("%d %d\n", (i + 1), list->data[i]);
}

Status init(LinearList **list)
{
    *list = (LinearList *)malloc(sizeof(LinearList));
    if (*list == NULL)
        exit(ERROR);
    (*list)->data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    if ((*list)->data == NULL)
        exit(ERROR);
    (*list)->listSize = InitSize;
    (*list)->listLength = 0;
    return OK;
}

Status clear(LinearList *list)
{
    free(list->data);
    list->listSize = 0;
    list->listLength = 0;
    return OK;
}

Status get(LinearList *list, int pos, ElemType *elem)
{
    if (pos < 1 || pos > list->listLength)
        exit(ERROR);
    *elem = list->data[pos - 1];
    return OK;
}

Status insert(LinearList *list, ElemType newElem, int insertPos)
{
    if (insertPos < 1 || insertPos > list->listLength + 1)
        exit(ERROR);
    if (list->listLength + 1 >= list->listSize)
    {
        ElemType *newData = (ElemType *)realloc(list->data, (list->listSize + IncrementSize) * sizeof(ElemType));
        if (newData == NULL)
            exit(OVERFLOW);
        list->data = newData;
        list->listSize += IncrementSize;
    }
    for (int i = list->listLength - 1; i >= insertPos - 1; --i)
        list->data[i + 1] = list->data[i];
    list->data[insertPos - 1] = newElem;
    list->listLength += 1;
    return OK;
}

Status erase(LinearList *list, int deletePos, ElemType *deleteElem)
{
    if (deletePos < 1 || deletePos > list->listLength)
        exit(ERROR);
    *deleteElem = list->data[deletePos - 1];
    for (int i = deletePos - 1; i < list->listLength; ++i)
        list->data[i] = list->data[i + 1];
    list->listLength -= 1;
    return OK;
}

int main(void)
{
    Status flg;
    LinearList *list;
    int n;
    ElemType e;
    int p;
    while (scanf("%d", &n) != EOF)
    {
        switch (n)
        {
            case 0:
                printf("Now the list is:\n");
                show(list);
                break;
            case 1:
                printf("List was Initialized.\n");
                flg = init(&list);
                break;
            case 2:
                printf("Insert an Elem (e) in Pos (p):\n");
                scanf("%d %d", &e, &p);
                flg = insert(list, e, p);
                break;
            case 3:
                printf("Delete an Elem (e) at Pos(p):\n");
                scanf("%d", &p);
                flg = erase(list, p, &e);
                printf("The elem (e) which you deleted is: %d.\n", e);
                break;
            default:
                break;
        }
    }
    clear(list);
    return 0;
}

