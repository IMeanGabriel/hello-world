#include<bits/stdc++.h>
using namespace std;
const int MAXN=100006;

void f2(int i, int j) {
    if (i > j)
      return;
    cout<<i<<" ";
    f2(i + 1, j);
  }

int f1(int n) 
{
    if (n == 1)
      return 1;
    return n * f1(n - 1);
  }


int arr[MAXN];
int len;
int f3(int[], int begin) {
    if (begin == len- 1) {
      return arr[begin];
    }
    return arr[begin] + f3(arr, begin + 1);
  }

  
int main()
{
    cout<<f1(5)<<endl;
    f2(1,8);

    int n;

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<f3(arr,1);
    return 0;
}