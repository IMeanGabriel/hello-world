#include<iostream>

using namespace std;

int get(int *p)
{
    *p = 5;
    return *p;
}

int main()
{
    int a = 1;
    cout<<a<<endl;
    get(a);
    cout<<a<<endl;
    return 0;
}