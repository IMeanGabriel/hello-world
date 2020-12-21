#include<bits/stdc++.h>
using namespace std;
const int MAXN=100006;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int a[MAXN];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((a[i]&a[j])>=(a[i]^a[j]))
                {
                    // printf("that is %d and %d\n",a[i],a[j]);
                    // printf("former %d latter %d\n",(a[i]&a[j]),(a[i]^a[j]));
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}