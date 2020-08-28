// #include <bits/stdc++.h>
// using namespace std;
// char str1[1006];
 
// int main()
// {
//     while(cin>>str1)
// {
//  double tmp;
//     int len = strlen(str1);
//     for(int i = 2; i < len; i++)
//     {
//         int temp = str1[i]-'0';
//         tmp = tmp + temp * pow(0.125,i-1);
//     }
     
//     printf("%s[8]=%.45g[10]\n",str1,tmp);
// }
//     return 0;
// }
 


// #include <bits/stdc++.h>
// using namespace std;
// char s[20];
 
 
// int main(){
//     cin>>s;
//     double t;
//     int len = strlen(s),i;
//     for(i = 2; i < len; i++){
//         int temp = s[i]-'0';
//         t = t + temp * pow(0.125,i-1);
//     }
     
//     printf("%s[8]=%.45g[10]",s,t);
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
char s[3006];
int num[3006];
 
int main()
{
    int len, tmp;
    while(cin >> s) {
        memset(num, 0, sizeof(num));
        int t = 0;
        len = strlen(s);
        for(int i=len-1; i>1; i--)
        {
            tmp = s[i] - '0';
            int k = 0;
            for(int j=0;j<t || tmp!=0;j++,k++)
            {
                tmp = tmp *10 + num[j];
                num[k] = tmp / 8;
                tmp %= 8;
            }
            t = k;
        }
        cout<< s << "[8]=0." ;
        for(int i=0; i<t; i++)
            cout << num[i];
        cout << "[10]"<< endl;
    }
    return 0;
}