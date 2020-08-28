#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1,m1,s1,h2,m2,s2;
    scanf("%d:%d:%d",&h1,&m1,&s1);
    scanf("%d:%d:%d",&h2,&m2,&s2);
    int t1=h1*3600+m1*60+s1;
    int t2=h2*3600+m2*60+s2;
    cout<<abs(t1-t2);
    return 0;
}
