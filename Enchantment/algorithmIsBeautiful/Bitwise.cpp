#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int f1=1,f2=1,ans;
    scanf("%d",&n);
    if(n==1||n==2)
    {
        ans=1;
    }
    else
    {
        for(int i=1;i<=n-2;i++)
        {
            ans=(f1+f2)%10007;
            f1=f2%10007;
            f2=ans%10007;
        }
    }
    printf("%d",ans);
    return 0;
}
