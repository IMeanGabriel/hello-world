#include<bits/stdc++.h>
using namespace std;
const int MAXN=1006;
int mat[MAXN][MAXN]={0};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    int n,m,a,b;
    int flg=0;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=1;i<=n-a+1;i++)
    {
        for(int j=1;j<=m-b+1;j++)
        {
            int tmp=mat[i][j];
            for(int k=i;k<=i+a-1;k++)
            {
                for(int q=j;q<=j+b-1;q++)
                {
                    
                    mat[k][q]-=tmp;
                    // cout<<"i="<<i<<" j="<<j<<endl;
                    // cout<<"k="<<k<<" q="<<q<<endl;
                    if(mat[k][q]<0) flg=1;
                }
            }
        }
    }
    //if(flg==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // if(mat[i][j]!=0)
                // {
                //     flg=1;
                //     break;
                // }
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    if(flg==1)
    {
        cout<<"QAQ"<<endl;
    }
    else
    {
        cout<<"^ ^"<<endl;
    }
    }
    
}