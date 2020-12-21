#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
string s;
string a="chi1 huo3 guo1";
int main()
{
    ios::sync_with_stdio(false);
    int cnt=0;
    int len=a.length();
    bool flag=0;
    int sum=0,k;
    while(getline(cin,s))
    {
        if(s==".")break;
        cnt++;
        int n=s.length();
        if(n<len)continue;
        for(int i=0;i<n-len+1;i++)
        {
            string t=s.substr(i,len);
            if(t==a)
            {
                if(!flag)
                {
                    flag=1;
                    k=cnt;
                }
                sum++;
            }
        }
    }
    printf("%d\n",cnt);
    if(!flag)printf("-_-#\n");
    else printf("%d %d\n",k,sum);
    return 0;
}
