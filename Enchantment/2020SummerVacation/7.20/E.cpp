//Hanks趣味问题
//WANTING WANG
//2019.03 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a0,a1,b0,b1;
int n,ans;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
    {
        return gcd(b,a%b);
    }
}

int t()
{
    char ch=getchar();
    int k=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch<='9'&&ch>='0') k=k*10+ch-'0',ch=getchar();
    return k;
}
void P( int n)
{
    if(n>9) P(n/10);
    putchar(n%10+'0');
    return ;
}

int main()
{
    n=t();
    while(n--)
    {
        a0=t();
        a1=t();
        b0=t();
        b1=t();
        ans=0;
        for(int i=1;i*i<=b1;i++)
        {
            if(b1%i==0)
            {
                if(i%a1==0&&
                    gcd(i/a1,a0/a1)==1&&
                    gcd(b1/i,b1/b0)==1)
                    ans++;
            }
            int ii=b1/i;
            if(b1%ii==0
            &&ii!=i&&ii%a1==0
            &&gcd(ii/a1,a0/a1)==1
            &&gcd(b1/ii,b1/b0)==1)
            ans++;
        }
        P(ans);
        putchar('\n');
    }
    return 0;
}

// int main()
// {
//     n=t();
//     while(n--)
//     {
//         a0=t();a1=t();b0=t();b1=t();
//         ans=0;
//         for(int i=1;i<=sqrt(b1);i++)
//         {
//             if(b1%i==0)
//             {
//                 if(i%a1==0&&gcd(i/a1,a0/a1)==1&&gcd(b1/i,b1/b0)==1) 
//                 ans++;
//             }
//             int ii=b1/i;
//             if(b1%ii==0&&ii!=i&&ii%a1==0&&gcd(ii/a1,a0/a1)==1&&gcd(b1/ii,b1/b0)==1) 
//             ans++;
//         }
//         P(ans);putchar('\n');
//     }
//     return 0;
// }
