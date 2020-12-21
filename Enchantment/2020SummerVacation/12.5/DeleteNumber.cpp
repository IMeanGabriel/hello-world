#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[1006];
    int n;
    while(scanf("%s %d",a,&n)!=EOF)
    {
      while(n--)
      {
         int i;
         for(i=0;a[i+1] && a[i]>a[i+1];i++);
         a[i]=0;
         strcat(a,a+1+i);
       }
     cout<<a<<endl;
   }
return 0;
}
