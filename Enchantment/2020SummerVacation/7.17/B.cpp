#include<bits/stdc++.h>
using namespace std;

int cmn(int n,int m)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=(m-n+i);
        ans/=i;
    }
    return ans;
}

int summar(int m)
{
    int mult=0;
    for(int i=1;i<=m;i++)
    {
        mult+=cmn(i,m);
    }
    return mult;
}

int main()
{
    int n;
    int res=-1;
    char type[1006];
    int number[1006];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%c%d",&type[i],&number[i]);
        cout<<type[i]<<" "<<number[i]<<endl;
        // if(type[i]=='M')
        // {
        //     number[i]=summar(number[i]);
        // }
        // res=max(res,number[i]);
    }
    //cout<<res<<endl;

}

