#include<bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    if(n<=0)
        return 0;
    return countWaysCore(n,new int[]{1,5,10,25},3);
}

int countWaysCore(int n,int []coins,int cur)
{
    if(cur==0)
        return 1;
    int res=0;
    for(int i=0;i*coins[cur]<=n;i++)
    {
        int shengyu=n-i*coins[cur];
        res+=countWaysCore(shengyu,coins,cur-1);
    }
    return res;
}

int main()
{

}