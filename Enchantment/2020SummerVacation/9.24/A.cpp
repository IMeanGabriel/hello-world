#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100006;

void swap(int *a, int *b); //交换两个数
 
int array[MAXN];
int main()
{
	int T;
    scanf("%d",&T);
    while(T--)
    {

    int n;
    scanf("%d",&n);
    int array[50006];
	int  i, j;
	//初始化数组为10 9 8 7 6 5 4 3 2 1
	for (i = 1; i <= n; i++)
	{
		scanf("%d",&array[i]);
	}
	//排序，从a[0]开始排，从小到大
    int flg=0;
    int cnt=0;
	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
                //printf("%d and %d\n",array[i],array[j]);
                cnt++;
			}
		}
	}
    //printf("cnt=%d\n",cnt);
    //fpr(int i=1;i<=n;i++)
    if(cnt>((n-1)*n/2-1))
    printf("NO\n");
    else
    {
        printf("YES\n");

    }
    
    }
        //将十个数输出
	// for (i = 0; i < 10; i++)
	// 	printf("%d\n", array[i]);
	return    0;
}
void swap(int *a, int *b)
{
	int     c;
	 c = *a;
	*a = *b;
	*b =  c;
}


 
// //双向快速排序
// #include<bits/stdc++.h>
// using namespace std;
// int cnt;
// void QuickSort(int* arr,int left, int right)
// {
	
//     if (left > right)
// 	{
// 		return;
// 	}
// 	int i = left;
// 	int j = right;
// 	//最左边的为准基数
// 	int flag = arr[left];
// 	while (i != j)
// 	{
// 		//从右侧找到一个比标记小的值
// 		while (arr[j] > flag && i < j)
// 		{
// 			j--;
// 		}
// 		//从左侧找到一个比标记大的值
// 		while (arr[i] <= flag && i < j)
// 		{
// 			i++;
// 		}
// 		//交换找到的值,使左边小,右边大
// 		int temp = 0;
// 		if (i<j)
// 		{
// 			temp = arr[j];
// 			arr[j] = arr[i];
// 			arr[i] = temp;
//             cnt++;
//             cout<<"cnt="<<cnt<<endl;
// 		}
// 	}//完成while循环,此时i=j
 
// 	//交换准基数和相遇值,即将中值归位
// 	arr[left] = arr[i];
// 	arr[i] = flag;
 
// 	//将中值左,右侧的数据分别进行排序(递归)
// 	QuickSort(arr, left, i - 1);
// 	QuickSort(arr, i + 1, right);
 
// }
 
// int main()
// {
// 	int T;
//     int array[10006];
//     scanf("%d",&T);
//     while(T--)
//     {

//     int n;
//     scanf("%d",&n);
//     memset(array,0,sizeof(array));
// 	int  i, j;
// 	//初始化数组为10 9 8 7 6 5 4 3 2 1
// 	for (i = 1; i <= n; i++)
// 	{
// 		scanf("%d",&array[i]);
// 	}
// 	//排序，从a[0]开始排，从小到大
//     int flg=0;
//     cnt=6;

// 	// int array[10] = { 879, 1, 34, 45, -123, 34, 5, 0, 45, 1 };
// 	QuickSort(array,1,n);
 
// 	//范围for循环打印数组
// 	for(int i=1;i<=n;i++)
//     {
//         printf("%d ",array[i]);
//     }
//     printf(" ans=%d",cnt);
// 	cout << endl;
//     }
// 	return 0;
// }