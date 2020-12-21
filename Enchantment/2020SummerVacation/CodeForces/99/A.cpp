#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ans=a+b+c;
        int times=ans/9;
        if(a<times||b<times||c<times)
        {
            cout<<"NO"<<endl;
        }
        else if(ans<9)
        {
            cout<<"NO"<<endl;
        }
        else if(ans%9==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}