// #include <bits/stdc++.h>
// using namespace std;
// #define  LISTINCREMENT 10
// #define LIST_INIT_SIZE 100

// typedef int Elemtype;

// typedef struct {
//     Elemtype * data;
//     int length;
//     int listsize;
// }SqList;


// void InitList_Sq(SqList & newList) {
//     newList.data =(Elemtype *)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
//     if(!newList.data)
//         exit(OVERFLOW);
//     newList.listsize = LIST_INIT_SIZE;
//     //newList.data = new Elemtype[newList.size];
//     newList.length = 0;

// }

// // void DestroyList(SqList & newList) {
// //     newList.length = 0;
// //     newList.data = 0;
// //     delete[] newList.data;
// //     newList.data = NULL;
// // }

// // void ClearList(SqList & newList) {
// //     newList.length = 0;
// //     delete[] newList.data;
// //     newList.data = NULL;
// //     newList.data = new Elemtype[newList.listsize];

// // }

// // bool ListEmpty(SqList newList) {
// //     return newList.length;
// // }

// // int ListLength(SqList newList) {
// //     return newList.length;
// // }

// // void GetElem(SqList newList, int i, Elemtype &e) {
// //     if (ListEmpty(newList)) {
// //         cout << "EMPTY" << endl;
// //         return;
// //     }
// //     if (i<1 || i>newList.length) {
// //         cout << "EXCEED" << endl;
// //         return;
// //     }
// //     e = newList.data[i - 1];
// // }

// // //判读元素的位置的函数
// // //我们这里直接返回该元素的下标
// // int LocationElem(SqList newList, Elemtype e){
// //     int i;
// //     for (i = 0; i < newList.length; i++) {
// //         if (newList.data[i] == e) {
// //             return i;
// //         }
// //     }
// //     return -1;
// // }

// // void PriorElem(SqList newList, Elemtype cur_e, Elemtype & pre_e) {
// //     int location = 0;
// //     location = LocationElem(newList, cur_e);
// //     //如果Location是-1，说明cur_e不在线性表中
// //     if (location == -1) {
// //         cout <<cur_e<< "不在线性表中" << endl;
// //         return;
// //     }
// //     //如果Location是0，说明cur_e在线性表第一个位置，没有前一个元素
// //     if (location == 0)
// //     {
// //         cout << cur_e << "是线性表的第一个元素，没有前驱" << endl;
// //         return;
// //     }
// //     pre_e = newList.data[location - 1];
// // }

// // //获取后驱元素
// // void NextElem(SqList newList, Elemtype cur_e, Elemtype & next_e) {
// //     int location = 0;
// //     location = LocationElem(newList, cur_e);
// //     //如果Location是-1，说明cur_e不在线性表中
// //     if (location == -1) {
// //         cout << cur_e << "不在线性表中" << endl;
// //         return;
// //     }
// //     //如果Location是0，说明cur_e在线性表最后一个位置，没有后一个元素
// //     if (location == newList.length-1)
// //     {
// //         cout << cur_e << "是线性表的最后一个元素，没有后驱" << endl;
// //         return;
// //     }
// //     next_e = newList.data[location - 1];
// // }

// //向线性表中插入一个元素，这里我们需要判断插入位置是否合法
// //除此之外，我们还需要检测元素的容量是否已经到达了最大值
// void Listinsert(SqList & newList, int i, Elemtype e) {
//     //插入的位置不合法
//     if (i<1 || i>newList.length+1) {
//         cout << "Please check" << endl;
//         return;
//     }
//     int j = 0;
//     //此时达到了线性表的最大容量，我们需要重新为线性表分配新的内存。
//     if (newList.length == newList.listsize) {
//         //先保存之前的内容。
//         Elemtype * p =new Elemtype[newList.length];
//         for (j = 0; j < newList.length; j++) {
//             p[j] = newList.data[j];
//         }
//         //扩大容量
//         newList.listsize += LISTINCREMENT;
//         delete[] newList.data;
//         //重新分配内存
//         newList.data = new Elemtype[newList.listsize];
//         //恢复之前内容
//         for (j = 0; j < newList.length; j++) {
//             newList.data[j] = p[j];
//         }
//     }
//     //插入内容
//     for (int k = newList.length; k >i-1; k-- ){
//         newList.data[k]=newList.data[k-1];
//     }
//     newList.data[i - 1] = e;
//     ++newList.length;
// }

// //线性表删除一个元素，我们需要判断删除的位置是否合法
// void Listdelete(SqList & newList, int i) {
//     //删除的位置不合法
//     if (i<1 || i>newList.length) {
//         cout << "请检查插入位置是否正确" << endl;
//         return;
//     }
//     for (int j = i - 1; j < newList.length; j++) {
//         newList.data[j] = newList.data[j + 1];
//     }
//     --newList.length;
// }

// //按照元素的值，来删除对应元素的内容，
// //这个时候我们通过传个参数，来决定我们是删除第一个该元素，
// //0,删除一个，1，删除所有
// //还是把所有的元素都给删除了
// // //如果不存在该元素，就直接返回
// // void Listdelete_data(SqList & newList, Elemtype e,int order) {
// //    int flag=0;
// //     for (int i = 0; i < newList.length; i++) {
// //         if (newList.data[i] == e) {
// //             flag=1;
// //             //删除对应的位置上的元素，而且i也要减少一个
// //             Listdelete(newList, i + 1);
// //             --i;
// //             if (order == 0) {

// //                 return;
// //             }
// //         }
// //     }
// //     if(flag==1)
// //     return ;
// //     cout << e << "不在线性表中" << endl;
// // }

// // //连接两个线性表
// // void Connect_two_List(SqList a, SqList b, SqList & c) {
// //     //对c进行一些数据初始化
// //     c.length = c.listsize = a.length + b.length;
// //     c.data = new Elemtype[c.listsize];

// //     //这里采用指针的方式进行数据的移动,我们先把a和b数据第一个和最后一个元素的位置找出来
// //     int i = 0;
// //     int j = 0;
// //     int k = 0;

// //     while (i <= a.length-1 && j<= b.length-1) {
// //         if (a.data[i] < b.data[j])
// //         {
// //             c.data[k++] = a.data[i++];

// //         }
// //         else if(a.data[i] > b.data[j]) c.data[k++] = b.data[j++];
// //         else {
// //             c.data[k++] = b.data[j++]; i++; --c.length;
// //         }
// //     }
// //     while (i <= a.length - 1)
// //     {
// //         c.data[k++] = a.data[i++];
// //     }
// //     while (j <= b.length - 1)
// //     {
// //         c.data[k++] = b.data[j++];
// //     }
// // }

// void print(SqList & L) {
//     for (int i = 0; i < L.length; i++) {
//         cout << L.data[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     SqList _List;
//     InitList_Sq(_List);
//     cout<<ListLength(_List)<<endl;
//     Listinsert(_List,0,1);
//     Listinsert(_List,1,5);
//     Listinsert(_List,1,8);
//     cout<<ListLength(_List)<<endl;
//     cout<<"succeeded"<<endl;
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
#define  LISTINCREMENT 10
#define LIST_INIT_SIZE 100

typedef int Elemtype;//typedef 类型定义标识符，为一个数据类型或者结构重新定义一个名称;
                    //将整型int关键字重新命名为 Elemtype

typedef struct
{
    Elemtype * data;
    int length;//记录已存储的数据长度
    int listsize;//记录该顺序表大小
}SqList;


void InitList_Sq(SqList & newList)
{
    newList.data =(Elemtype *)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
    if(!newList.data)
        exit(OVERFLOW);
    newList.listsize = LIST_INIT_SIZE;
    newList.length = 0;

}

void Listinsert(SqList & newList, int i, Elemtype e)
{
    if (newList.length == newList.listsize)
    {
        int j;
        Elemtype * p =new Elemtype[newList.length];
        for (int j = 0; j < newList.length; j++)
        {
            p[j] = newList.data[j];
        }
        newList.listsize += LISTINCREMENT;
        delete[] newList.data;
        newList.data = new Elemtype[newList.listsize];
        for (j = 0; j < newList.length; j++)
        {
            newList.data[j] = p[j];
        }
    }
    for (int k = newList.length; k >i-1; k-- )
    {
        newList.data[k]=newList.data[k-1];
    }
    newList.data[i - 1] = e;
    newList.length++;
}

void Listdelete(SqList & newList, int i) {
    for (int j = i - 1; j < newList.length; j++) {
        newList.data[j] = newList.data[j + 1];
    }
    newList.length--;
}

void print(SqList & L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    SqList _List;
    InitList_Sq(_List);
    int n,ele;
    //cout<<ListLength(_List)<<endl;
    cout<<"Insert an element:";
    cin>>ele;
    cout<<"at where?";
    cin>>n;
    Listinsert(_List,n,ele);
    cout<<"Insert an element:";
    cin>>ele;
    cout<<"at where?";
    cin>>n;
    Listinsert(_List,n,ele);
    cout<<"Insert an element:";
    cin>>ele;
    cout<<"at where?";
    cin>>n;
    Listinsert(_List,n,ele);
    cout<<"Delete an element";
    cout<<"...where?";
    cin>>n;
    Listdelete(_List,n);
    print(_List);
    cout<<"succeeded"<<endl;
    return 0;
}
