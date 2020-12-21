/*2018.11
*数据结构与算法-第7章习题T3算法设计题
*(2)试写一个判别给定二叉树是否为二叉排序树的算法
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int keyType;
typedef int infoType;

typedef struct
{
	keyType key;
	infoType otherinfo;
}elemtype;//结点的结构体类型

typedef struct bitreenode
{
	elemtype data;
	struct bitreenode *lchild,*rchild;
}bitreenode,*bitree;//二叉树的结构体类型

int storenum=0;//用于存储中序遍历时父节点的值
int flag=1;//用于判别父节点的值是否大于子节点的值

void createbitree(bitree &t)/*以先序遍历的顺序建立二叉树*/
{
	elemtype e;
	printf("请输入两个值,分别代表key和其他数据项:");
	scanf("%d%d",&e.key,&e.otherinfo);
	if(e.key==-9999)
		t=NULL;
	else
	{
		t=(bitree)malloc(sizeof(bitreenode));
		t->data=e;
		createbitree(t->lchild);
		createbitree(t->rchild);
	}
}

int isbstree(bitree t)/*判断是否为二叉排序树*/
{
	if(t->lchild && flag)
		isbstree(t->lchild);
	if(t->data.key<storenum)
		flag=0;//左子树一支中若父节点的值小于子节点,则flag为0
	storenum=t->data.key;//更新storenum的值
	if(t->rchild && flag)
		isbstree(t->rchild);
	return flag;
}

void inOrderTraverse(bitree t)/*中序遍历二叉树*/
{
	if(t)
	{
		inOrderTraverse(t->lchild);
		printf("%d ",t->data);
		inOrderTraverse(t->rchild);
	}
}

int main()
{
	printf("此二叉树中所有数据目前应均为互不相同的正整数\n\n");
	bitree testtree;
	createbitree(testtree);
	inOrderTraverse(testtree);
	if(isbstree(testtree))
		printf("给定二叉树是二叉排序树\n");
	else
		printf("给定二叉树不是二叉排序树\n");
	return 0;
}
