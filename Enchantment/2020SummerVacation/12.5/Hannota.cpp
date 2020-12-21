#include <bits/stdc++.h>
using namespace std;

// void hannota(int n, char x, char y, char z)
// {
//     if (n == 0)
//         return;
//     hannota(n - 1, x, z, y);
//     cnt++;
//     hannota(n - 1, y, x, z);
// }


// int main()
// {
//     ios::sync_with_stdio(0);
//     long long int a[150];
//     a[0]=1;
//     for(long long int i=1;i<130;i++)
//     a[i]=a[i-1]*2;
//     long long int n;
//     while (cin>>n)
//     {
//         cout<<a[n]-1<<endl;
//     }
//     return 0;
// }


int main()
{
    ios::sync_with_stdio(0);
    long long int n;
    while (cin>>n)
    {
        double ans=1;
        for(int i=1;i<n;i++){
            ans=ans*2+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
