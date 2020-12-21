// #include <bits/stdc++.h>
// using namespace std;
// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0

// #define STACK_INIT_SIZE 100
// #define STACKNCREMRNT 10

// #define MAX_TREE_SIZE 100
// #define MAXN 10006

// #define MAX_VERTEX_NUM 20


// // typedef float KeyType;
//  typedef int KeyType;
// // typedef char *KeyType;

// typedef struct{
//     KeyType key;
// }ElemType;

// #define EQ(a,b) ((a)==(b))
// #define LT(a,b) ((a)<(b))
// #define LQ(a,b) ((a)<=(b))
// #define RT(a,b) ((a)>(b))
// #define RQ(a,b) ((a)>=(b))

// // #define EQ(a,b) (!strcmp((a),(b)))
// // #define LT(a,b) (strcmp((a),(b))<0)
// // #define LQ(a,b) (strcmp((a),(b))<=0)
// // #define RT(a,b) (strcmp((a),(b))>0)
// // #define RQ(a,b) (strcmp((a),(b))>=0)

// typedef struct
// {
//     ElemType * elem;
//     int length;
// }SSTable;

// int Init_SSTable(SSTable &ST)
// {
//     ST.elem=(ElemType*)malloc(SSTABLE_INIT_SIZE*sizeof(Elemtype));
//     if(!ST.elem)
//         return FALSE;
//     ST.length=0;
// }

// int SSTableInsert_Seq(SSTable & ST,int i,int e)
// {
//     ElemType *p,*q;
//     if(i<i||i>ST.length+1)
//         return ERROR;
//     q=&(ST.elem[i-1]);
//     for(p=&(ST.elem[ST.length-1]);)
// }

// int Search_Seq(SSTable ST, KeyType key)
// {
//     int i;
//     ST.elem[0].key=key;
//     for(i=ST.length;!EQ(ST.elem[i].key,key);--i);
//     return i;
// }

// int Search_Bin(SSTable ST, KeyType key)
// {
//     int low=1;
//     int high=ST.length;
//     while(low<=high)
//     {
//         mid=(low+high)/2;
//         if(EQ(key,ST.elem[mid].key))
//             return mid;
//         else if(LT(key,ST.elem[mid].key))
//             high=mid-1;
//         else
//             low = mid + 1;
//     }
//     return 0;
// }

// int main()
// {
//     SSTable ss;
//     int n;
//     scanf("%d",&n);
//     ss.length=n;
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&ss.elem[i]);
//     }
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<bits/stdc++.h>
// using namespace std;

// #define SSTable_INIT_SIZE 100//初始分配量 
// #define SSTableINCREMRNT 10//分配增量 

// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
// #define INFEASIBLE -1
// //#define OVERFLOW -2

// typedef int Status;
// typedef int KeyType;
// //typedef BiTree SOSTree;//次优查找树采用二叉链表储存结构 

// typedef struct {
// 	int key;
// } ElemType;

// typedef struct {
// 	ElemType *elem;//数据元素存储空间基值，建表时按书记长度分配，0号单元留空
// 	int length;//表长度
// } SSTable;

// typedef struct BiTNode {
// 	ElemType data;
// 	struct BiTNode *lchild,*rchild;//左右孩子指针
	
// } BiTNode,*BiTree;
// //创造空线性表L
// int cnt1=0,cnt2=0;

// Status InitSSTable_Seq(SSTable& ST) {
// 	ST.elem=(ElemType*)malloc(SSTable_INIT_SIZE*sizeof(ElemType));
// 	if(!ST.elem)return FALSE;//储存分配失败
// 	ST.length=0;//空表长度为0
// 	return OK;
// }
// //个数小于100的线性表
// Status SSTableInsert_Seq(SSTable& ST,int i,int e) { //顺序线性表中第i个位置插入元素e,i的合法值为1---ListLength_Sq(L)+1
// 	ElemType *p,*q;
// 	if(i<1||i>ST.length+1)return ERROR;
// 	q=&(ST.elem[i-1]);//q为插入位置
// 	for(p=&(ST.elem[ST.length-1]); p>=q; p--)*(p+1)=*p; //插入位置及之后元素后移
// 	(*q).key=e;//插入e
// 	++ST.length;//表长加一
// 	return OK;
// }

// //线性表插入数据
// Status SSTableIn_Sq(SSTable& ST) {
// 	int e, i = 1;
// 	do {
// 		scanf("%d", &e);
// 		SSTableInsert_Seq(ST, i, e);
// 		i++;
// 	} while (getchar() == ' ');
// 	printf("\nSuccessfully inserted!\n");
// 	return OK;
// }
// //判断顺序表中的值和key比较值是否相等
// int EQ(int key,int num) { 
// 	if(num==key)return TRUE;
// 	else return FALSE;
// }
// //判断顺序表中的值是否大于key比较值
// int LT(int key,int num) { 
// 	if(num>key)return TRUE;
// 	else return FALSE;
// }
// //在顺序表ST中顺序查找其关键字等于key，找到返回位置，否则返回0
// int Search_Seq(SSTable ST,KeyType key) { 
// 	int i=0;
//     cnt1=1;
// 	ST.elem[0].key=key;//"哨兵"
//     cout<<ST.elem[<<"******"<<endl;
// 	for(i=0; !EQ(ST.elem[i].key,key)&&i<=ST.length; i++)
//     {
//         cnt1++; //从后往前找
//         cout<<ST.elem[i].key<<"*****"<<endl;
//     }  
// 	return i+1;//找不到时，i为0
// }//Search_Seq
// //在顺序表ST中折半查找其关键字等于key，找到返回位置，否则返回0
// int Search_Bin(SSTable ST,KeyType key){
// 	int low=1,high=ST.length,mid;//置区间初值 
// 	while(low<=high){
// 		mid=(low+high)/2;
//         cnt2++;
// 		if(EQ(key,ST.elem[mid].key))return mid+1;//找到待查元素 
// 		else if(LT(key,ST.elem[mid].key))high=mid-1;//继续在前半区间进行查找 
// 		else low=mid+1;//后半区间进行查找 
// 	}
// 	return 0;//顺序表中不存在待查元素 
// }
// //由有序表R[low...high]及器累计权值表sw(其中sw[0]==0)递归构造次优查找树T 
// void SecondOptimal(BiTree &T,ElemType R[],float sw[],int low,int high){
// 	int i=low,min=abs(sw[high]-sw[low]);
// }

// int main() {
// 	SSTable ST;
// 	int num1,num2;
// 	int key_to_search;
// 	printf("Input the sequence:\n");
//     InitSSTable_Seq(ST);
//     SSTableIn_Sq(ST);

//     printf("Input the key number: ");
//     scanf("%d",&key_to_search);	

// 	num1=Search_Seq(ST,key_to_search);
// 	num2=Search_Bin(ST,key_to_search);

// 	printf("Output the position by sequential search: %d\n",num1);
//     printf("Output times of sequential search: %d\n",cnt1);

//     printf("Output the position by binary search: %d\n",num2);
//     printf("Output times of binary search: %d\n",cnt2);

// }








#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define SSTable_INIT_SIZE 100//初始分配量 
#define SSTableINCREMRNT 10//分配增量 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int KeyType;
//typedef BiTree SOSTree;//次优查找树采用二叉链表储存结构 

typedef struct {
	int key;
} ElemType;

typedef struct {
	ElemType *elem;//数据元素存储空间基值，建表时按书记长度分配，0号单元留空
	int length;//表长度
} SSTable;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild,*rchild;//左右孩子指针
	
} BiTNode,*BiTree;
//创造空线性表L
Status InitSSTable_Seq(SSTable& ST) {
	ST.elem=(ElemType*)malloc(SSTable_INIT_SIZE*sizeof(ElemType));
	if(!ST.elem)return FALSE;//储存分配失败
	ST.length=0;//空表长度为0
	return OK;
}
//个数小于100的线性表
Status SSTableInsert_Seq(SSTable& ST,int i,int e) { //顺序线性表中第i个位置插入元素e,i的合法值为1---ListLength_Sq(L)+1
	ElemType *p,*q;
	if(i<1||i>ST.length+1)return ERROR;
	q=&(ST.elem[i-1]);//q为插入位置
	for(p=&(ST.elem[ST.length-1]); p>=q; p--)*(p+1)=*p; //插入位置及之后元素后移
	(*q).key=e;//插入e
	++ST.length;//表长加一
	return OK;
}

//线性表插入数据
Status SSTableIn_Sq(SSTable& ST) {
	int e, i = 1;
	do {
		scanf("%d", &e);
		SSTableInsert_Seq(ST, i, e);
		i++;
	} while (getchar() == ' ');
	printf("\n成功插入数据串\n");
    // for(int i=0;i<=6;i++){
    //     printf("%d ",ST.elem[i].key);
    // }
	return OK;
}
//判断顺序表中的值和key比较值是否相等
int EQ(int key,int num) { 
	if(num==key)return TRUE;
	else return FALSE;
}
//判断顺序表中的值是否大于key比较值
int LT(int key,int num) { 
	if(num>key)return TRUE;
	else return FALSE;
}
//在顺序表ST中顺序查找其关键字等于key，找到返回位置，否则返回0
int Search_Seq(SSTable ST,KeyType key) { 
	int i=0;
	ST.elem[0].key=key;//"哨兵"
	for(i=ST.length; !EQ(ST.elem[i].key,key); --i); //从后往前找
	return i;//找不到时，i为0
}//Search_Seq
//在顺序表ST中折半查找其关键字等于key，找到返回位置，否则返回0
int Search_Bin(SSTable ST,KeyType key){
	int low=1,high=ST.length,mid;//置区间初值 
	while(low<=high){
		mid=(low+high)/2;
		if(EQ(key,ST.elem[mid].key))return mid;//找到待查元素 
		else if(LT(key,ST.elem[mid].key))high=mid-1;//继续在前半区间进行查找 
		else low=mid+1;//后半区间进行查找 
	}
	return 0;//顺序表中不存在待查元素 
}
//由有序表R[low...high]及器累计权值表sw(其中sw[0]==0)递归构造次优查找树T 


int main() {
	SSTable ST;
	int num;
	
	InitSSTable_Seq(ST);
	SSTableIn_Sq(ST);
	
	//num=Search_Seq(ST,5);
	num=Search_Bin(ST,5);
	printf("输出查找的数据位置为:%d",num);
}
