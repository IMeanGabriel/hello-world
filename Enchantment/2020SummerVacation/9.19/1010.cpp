#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int a;
        int ans;
        scanf("%d",&n);
        scanf("%d",&ans);
        int flg=0;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&a);
            if(ans==a)
            {
                flg=1;
            }
            else
            {
                ans=a;
            }
            
                
        }
        if(flg==1)
            printf("NO\n");
        else
        {
            printf("YES\n");
        }
    }
}