#include<bits/stdc++.h>
using namespace std;



// int main()
// {

// }

// void bubblesort(A[], n)
// {
//     int round=0;
//     while(A)
//     {
//         round++;
//         for(int i=1;i<n;i++)
//         {

//         }
//     }

// }
// 　　> round = 0
// 　　> while A is not sorted
// 　　> > round := round + 1
// 　　> > for i := 1 to n - 1
// 　　> > > if (A[i] > A[i + 1])
// 　　> > > > swap(A[i], A[i + 1])


#define NUM 5
void arrsort(int[],int);
void arrout(int[],int);
int main(){
	 int a[NUM]={16,25,9,90,23};
	 
     arrout(a,NUM);//输出a数组中原始数据
	 arrsort(a,NUM);//对a数组中的数进行排序
     arrout(a,NUM);//输出排序后a数组中的数据
}
void arrsort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){ 
			  int temp =a[j+1];
			  a[j+1] = a[j];
			  a[j] = temp;
              cnt++;
			}
		}
	}
	
}
void arrout(int a[],int n){
   int i;
   for(i=0;i<n;i++){
    printf("%3d",a[i]);
   }
   printf("\n");
 }