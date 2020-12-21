#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000006;
int a[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n,k;
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&m,&n,&k);
        int delet=MAXN;
        int index=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<k)
            {
                if(delet>a[i])
                {
                    delet=a[i];
                    index=i;
                }
            }
        }
        //printf("delet %d index %d\n",delet,index);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i!=index)
            {
                ans=ans+2*abs(k-a[i]);
                //printf("tem ans=%d\n",ans);
            }
        }
        printf("%d\n",ans+2*k-2);
    }
}