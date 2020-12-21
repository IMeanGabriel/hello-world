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
        scanf("%d",&n);
        getchar();
        char a[MAXN];
        int b[MAXN];
        for(int i=1;i<=n;i++)
        {
            scanf("%c",&a[i]);
            b[i]=a[i]-'0';
            // printf("%c\n",a[i]);
        }
        int flg=0;
        int ans;
        if(n%2==1)
        {
            ans=2;
            for(int j=1;j<=n;j+=2)
            {

                if(b[j]%2==1)
                {
                    ans=1;
                    //printf("1\n");
                    flg=1;
                    continue;
                }
                // if(flg==0)
                // printf("2\n");
            }
        }
        else
        {
            ans=1;
            for(int j=2;j<=n;j+=2)
            {
                if(b[j]%2==0)
                {
                    ans=2;
                    //printf("2\n");
                    flg=1;
                    continue;
                }
                // if(flg==0)
                // printf("1\n");
            }
        }
        //getchar();
        // for(int i=1;i<=n;i++)
        // {
        //     printf("%d* ",b[i]);
        // }
        //for(int i)
        printf("%d\n",ans);
    }
}