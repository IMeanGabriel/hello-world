#include<bits/stdc++.h>
using namespace std;
const int MAXN=100006;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        int a[MAXN];
        scanf("%d%d",&n,&k);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        //sort(a+1,a+n+1);
int index=1;              
        for(int i=index;i<=n-k+1;i++)
        {
int mina=MAXN;  

            for(int j=i;j<=i+k-1;j++)
            {
                mina=min(mina,a[j]);
                index=j;

            }
            //cout<<"now the min is "<<mina<<endl;
            for(int j=i;j<=i+k-1;j++)
            {
                a[j]-=mina;
                //cout<<a[j]<<" ";
            }
            //cout<<endl;
            ans+=mina;
        }
        printf("%d\n",ans);
    }
}