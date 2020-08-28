#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n,ans,temp;
    int T;
    int a[10];
    scanf("%d",&T);
    // while(T--)
    // {
    //     int tmp=0,temp=0;
    //     for(int i=1;i<=9;i++)
    //     {
    //         scanf("%d",&a[i]);
    //     a[i]--;
    //     tmp^=a[i];
    //     }
    // int cnt=0;
    // for(int i=1;i<9;i++)
    // {
    //     for(int j=i+1;j<=9;j++)
    //     {
    //         temp=tmp;
    //         temp^=a[i];
    //         temp^=a[j];
    //         if(temp==1)
    //         {
    //               cnt++;    
    //               printf("%d %d\n",i,j);
    //               break;          
    //         }

    //     }
    // }
    // printf("%d\n",9-cnt);

    while(cin>>n)
    {
        temp=0;
        for(int i=0;i<n;i++)
        {
            cin>>ans;
            temp^=ans;
        }
        if(temp==0)  cout<<"latter"<<endl;
        else cout<<"former"<<endl;
     }
    return 0;
}


