// #include <iostream>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// #include<string>
// #include<map>
// const int maxn=10000006;
// const int mod=10000;
// #define me(a) memset(a,0,sizeof(a))
// #define ll long long
// using namespace std;

// int FBNQ[22] = {0};
 
// void get_FBNQ()
// {
//     FBNQ[1] = 1;
//     FBNQ[2] = 1;
//     for(int i = 3; i < 22; i++)
//     {
//         FBNQ[i] = FBNQ[i - 1] + FBNQ[i - 2];
//     }
// }
// bool is_FBNQ(int n)
// {
//     for(int i = 1; i < 22; i++)
//     {
//         if(n == FBNQ[i])
//         {
//             return true;
//         }
//     }
//     return false;
// }
 
// int main(void)
// {
//     get_FBNQ();
//     int n;
//     while(scanf("%d", &n), n != 0)
//     {
//         if(is_FBNQ(n))//特判
//         {
//             printf("%d\n", n);
//         }
 
//         while(!is_FBNQ(n))//当n不是斐波那契数
//         {
//             for(int i = 21; i >= 0; i--)//找到小于n的最大斐波那契数
//             {
//                 if(FBNQ[i] <= n)
//                 {
//                     printf("%d+", FBNQ[i]);
//                     n = n - FBNQ[i];
//                     break;
//                 }
//             }
//         }
//         printf("%d\n", n);
//     }
//     printf("%d", n);
// }
 






// struct node{
//     int a[2][2];
//     node()
//     {
//         memset(a,0,sizeof(a));
//     }
// };
// node jx(node a,node b)
// {
//     node s;
//     for(int i=0;i<2;i++)
//         for(int j=0;j<2;j++)
//             for(int k=0;k<2;k++)
//                 s.a[i][k]=(s.a[i][k]+a.a[i][j]*b.a[j][k])%mod;
//     return s;
// }
// node qsort(node a,int n)
// {
//     node s;
//     for(int i=0;i<2;i++)
//         s.a[i][i]=1;
//     while(n)
//     {
//         if(n&1)
//             s=jx(s,a);
//         a=jx(a,a);
//         n>>=1;
//     }
//     return s;
// }
// int main()
// {
//     node a;
//     int n;
//     a.a[0][0]=a.a[1][0]=a.a[0][1]=1;
//     // while(cin>>n&&n!=-1)
//     // {
//     //     n++;
//     //     node s=qsort(a,n);
//     //     cout<<s.a[1][0]<<endl;
//     // }
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int a1,a2,a3;
//         int tmp1[maxn];
//         int tmp2[maxn];
//         int tmp3[maxn];
//         int number1=0,number2=0,number3=0;
//         scanf("%d",&a1);
//         for(int i=1;i<=a1;i++)
//         {
//             scanf("%d",&tmp1[i]);
//             if(tmp1[i]==1)
//             {
//                 node s=qsort(a,i+1);
//                 number1+=s.a[1][0];
//                 //cout<<s.a[1][0]<<" ";
//             }
//             //cout<<endl;
//         }
//         scanf("%d",&a2);
//         for(int i=1;i<=a2;i++)
//         {
//             scanf("%d",&tmp2[i]);
//             if(tmp2[i]==1)
//             {
//                 node s=qsort(a,i+1);
//                 number2+=s.a[1][0];
//                 //cout<<s.a[1][0]<<" ";
//             }
//             //cout<<endl;

//         }
//         //cout<<number1<<" "<<number2<<endl;
//         scanf("%d",&a3);
//         for(int i=1;i<=a3;i++)
//         {
//             scanf("%d",&tmp3[i]);
//             if(tmp3[i]==1)
//             {
//                 node s=qsort(a,i+1);
//                 number3+=s.a[1][0];
//                 //cout<<s.a[1][0]<<" ";
//             }
//             //cout<<number3<<endl;
//         }
//         for(int i=1;i<=maxn;i++)
//         {
//             node s=qsort(a,i+1);
//             // if(s.a[1][0]>50000)
//             // {
//             //     cout<<i<<endl;
//             //     break;
//             // }
//             //cout<<s.a[1][0]<<endl;
//             if(number1*number2-number3==s.a[1][0])
//             {
//                 cout<<i<<endl;
//                 break;
//             }
//         }
//         //cout<<number3<<" "<<number2<<" "<<number1<<endl;
//     }

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=3000006;
ull fi[MAXN];
int i;
int cases;
ull a1,a2,a3;

inline ull read()
{
    int n,x,i;
    ull ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            ans+=fi[i];
        }
    }
    return ans;
}

// void init()
// {
//     fi[1]=1;
//     fi[2]=2;
//     for(int i=3;i<MAXN;i++)
//     {
//         fi[i]=fi[i-1]+fi[i-2];
//     }
// }

int main()
{
    //init();


    //cout<<fi[4]<<endl;    
    fi[1]=1;
    fi[2]=2;
    for(int i=3;i<MAXN;i++)
    {
        fi[i]=fi[i-1]+fi[i-2];
    }
    scanf("%d",&cases);
    while(cases--)
    {
        a1=read();
        a2=read();
        a3=read();
        //cout<<a1<<" "<<a2<<" "<<a3<<endl;
        a1*=a2;

        for(i=1;a1-a3!=fi[i];i++);
        printf("%d\n",i);
    }

    return 0;
}