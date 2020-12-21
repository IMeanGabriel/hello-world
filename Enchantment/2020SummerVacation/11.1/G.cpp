#include<bits/stdc++.h>
#define ll long long
#define ms(x,a) memset(x,a,sizeof(x))
using namespace std;

// int sg(int c0,int c1,int c2,int c3) //1必胜 -1必败
// {
//     if(c0 == 0 && c1 == 0)  //只有c2,c3必败
//         return -1;
//     if(c0 == 1 && c1 == 0 && c2 == 0 && c3 == 0)    //只有一张0必败
//         return -1;
//     if(c1 == 1 && c0 == 0 && c2 == 0)   //只有一张1必败
//         return -1;
//     int f = 1;
//     if(c0 > 0)  //一张0和其他任意一张牌组合
//     {
//         f = min(f,sg(c0 - 1,c1,c2,c3));
//     }
//     if(c1 >= 2) //用一张2替换两张1
//         f = min(f,sg(c0,c1 - 2,c2 + 1,c3));
//     if(c1 > 0 && c2 > 0)    //用一张3替换一张1和一张2
//         f = min(f,sg(c0,c1 - 1,c2 - 1,c3 + 1));
//     if(f == -1) //后继存在必败，当前必胜；否则，必败
//         return 1;
//     return -1;
// }

int ck(ll c0,ll c1,ll c2,ll c3)
{
    if(c0 == c1 && c1 == c2 && c2 == c3 && c3 == 0)
    {
        return -1;
    }
    else
    {
        int f = 1;
        if(c3 == 0)
        {
            if(c1 == 0 && c2 == 0)
            {
                if(c0 == 0 || c0 % 2)
                {
                    f = -1;
                }
            }
            else
            {
                if(c0 % 2 == 0)
                {
                    if(c1 % 3 == 0)
                    {
                        f = -1;
                    }
                    else
                    {
                        if(c1 % 3 == 1 && c2 == 0)
                        {
                            f = -1;
                        }
                    }
                }
                else
                {
                    if(c1 % 3 == 1 && c2 > 0)
                    {
                        f = -1;
                    }
                    else if(c1 % 3 == 2 && c2 <= 1)
                    {
                        f = -1;
                    }
                }
            }
        }
        else
        {
            if(c0 % 2 == 0)
            {
                if(c1 % 3 == 0)
                {
                    f = -1;
                }
                else
                {
                    if(c1 % 3 == 1 && c2 == 0)
                    {
                        f = -1;
                    }
                }
            }
            else
            {
                if(c1 % 3 == 1 && c2 > 0)
                {
                    f = -1;
                }
                else if(c1 % 3 == 2 && c2 <= 1)
                {
                    f = -1;
                }
            }
        }
        return f;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ++ca)
    {
        ll c0,c1,c2,c3;
        scanf("%lld%lld%lld%lld",&c0,&c1,&c2,&c3);
        printf("Case #%d: ",ca);
        if(ck(c0,c1,c2,c3) == 1)
        {
            puts("Rabbit");
        }
        else
        {
            puts("Horse");
        }
    }
    return 0;
}
