#include <bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 100
#define STACKNCREMRNT 10

#define MAX_TREE_SIZE 100
#define MAXN 10006
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode,HuffmanTree[MAXN];
 
void select(HuffmanTree HT,int n,int *s1,int *s2)
{
    int i;
    int minn=MAXN;
    int tmp1=0,tmp2=0;
    for(i=1;i<=n;i++)
    {
        if(HT[i].parent==0 && HT[i].weight<minn)
        {
            minn=HT[i].weight;
            tmp1=i;
        }
    }
    *s1=tmp1;
    minn=MAXN;
    for( i=1;i<=n;i++)
    {
        if(HT[i].parent==0 && HT[i].weight<minn && tmp1 != i)
        {
            minn=HT[i].weight;
            tmp2=i;
        }
    }
    *s2=tmp2;
}
 
void HuffmanCoding(HuffmanTree HT,int n,int w[])
{
    int i;
    for(i=1;i<=n;i++)
    {
        HT[i]={w[i],0,0,0};
    }
    int m=2*n-1;
    for(;i<=m;i++)
    {
        HT[i]={0,0,0,0};
 
    }
    int s1,s2;
    for(i=n+1;i<=m;i++)
    {
        select(HT,i-1,&s1,&s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }


    char cd[n+1][n+1] ;
    int start;
 
    for(i=1;i<=n;i++)
    {
        cd[i][n-1]='\0';
        start=n-1;
        int c,f;
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)
                cd[i][--start]='0';
            else
                cd[i][--start]='1';
        }
        printf("Code %d : ",i);
        int j;
        for(j=start;cd[i][j]!='\0';j++)
            printf("%c",cd[i][j]);
        printf("\n");
    }   
}

//15 6 7 12 25 4 6 1 15

int main()
{
    int n,value;
    int w[MAXN];
    HuffmanTree HT;
    printf("Input the number of nodes:\n");
    scanf("%d",&n);
    printf("Input every node value with a space as interval:\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value);
        w[i]=value;
    }
     HuffmanCoding(HT,n,w);
    return 0;
}



