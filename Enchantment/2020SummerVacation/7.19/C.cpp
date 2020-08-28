#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int inf=0x3f3f3f3f;

int gcd(int m, int n)  
{  
    while(m>0)  
    {  
        int c = n % m;  
        n = m;  
        m = c;  
    }  
    return n;  
}

bool check(int a,int b)
{

	if(a==1||b==1)     // 两个正整数中，只有其中一个数值为1，两个正整数为互质数
		return true;
	if(gcd(a,b)>1)
        return false;
	else   
        return true;
}


int main()
{
    int t;
	scanf("%d",&t);
	while(t--)
	{
        int num1,num2;
        scanf("%d%d",&num1,&num2);
        if(check(num1,num2))
            printf("%d\n",num1+num2-1);
        else
            printf("%d\n",num1+num2-2);
    }
    return 0;
}
// 12 34
// 1233
// 1232
// 1 2 3 5 7 11
// 1 2 3 5 7 11 13 17 19 23 27 29 31