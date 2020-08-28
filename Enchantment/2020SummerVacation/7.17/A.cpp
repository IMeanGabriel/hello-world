// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     while(n--)
//     {
//         string ss;
//         cin>>ss;
//         int mark=0;
//         int flg=0;
//          if(ss[0]=='b')
//          {
//              cout<<"Dead Fang"<<endl;
//              continue;
//          }
//         // for(int i=2;i<ss.length();i++)
//         // {
//         //     if(ss[i]=='b')
//         //         mark=0;    
//         // }
//         for(int i=2;i<ss.length();i++)
//         {
//             if(ss[i]=='b')
//             {
//                 if(ss[i-1]=='a'&&ss[i-1]=='a')
//                 {
//                     cout<<"Sad Fang"<<endl;
//                     mark=1;
//                     continue;
//                 }
//                 if(ss[i-1]!='a')
//                 {
//                     cout<<"Dead Fang"<<endl;
//                     mark=1;
//                     continue;
//                 }
//             }
            
//         }
//         if(mark==0)
//         cout<<"Happy Fang"<<endl;
       
//     }
//     return 0;
// }


// h:
// s:b前有多个a
// d:b开头；b连续


#include<bits/stdc++.h>
using namespace std;
const int MAXN=10006;

int main()
{
    int n;
    char a[MAXN];
    scanf("%d",&n);
    int flg;
    while(n--)
    {
        scanf("%s",a);
        flg=0;
        int cnta=0,cntb=0;
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]=='b')
            {
                cntb++;
                if(a[i+1]!='b')
                {
                    if(cnta<cntb)
                    {
                        flg=2;
                        break;
                    }
                    else if(cnta>cntb)
                    {
                        flg=1;
                    }
                    else if(cnta=cntb)
                    {
                        flg=0;
                    }
                }
                else
                {
                    cnta++;
                }

                if(flg==0)
                    printf("Happy Fang\n");
                else if(flg==1)
                    printf("Sad Fang\n");
                else if(flg==2)
                    printf("Dead Fang\n");
            }
            return 0;
        }
    }
}