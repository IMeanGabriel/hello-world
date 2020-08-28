#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         string ss;
//         cin>>ss;
//         int ans=0;
//         int len=ss.length();
//         for(int j=len-1;j>=0;j--)
//         {
//             if(ss[j]>='A'&&ss[j]<='Z')
//             {
//                 ans+=(ss[j]-'A'+10)*pow(16,len-j-1);
//             }
//             if(ss[j]>=0&&ss[j]<='9')
//             {
//                 ans+=(ss[j]-'0')*pow(16,len-j-1);
//             }
//         }
//         printf("%o\n",ans);
//     }
//     return 0;
// }
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n, num, len, p;
    string is, os;
    cin>>n;
    while(n--)
    {
    
        cin>>is;
        len = is.size();
        os = "";
        for(int i = len-1;i >= 0;){
            p = 1;
            num = 0;
               
            for(int j = 0;j < 3 && i >= 0;j++,i--){ //转换成十进制
                if(is[i] <= '9' && is[i] >= '0'){
                    num += (is[i]-'0')*p;
                }
                else{
                    num += (is[i]-'A'+10)*p;
                }
                p *= 16;
            }
            
            for(int j = 0;j < 4;j++){//换成四个八位前不足四位0补齐
                os += (num%8)+'0';
                num /= 8;
            }
            
        }
        
        int k = os.size()-1; //去前导0
        while(os[k] == '0'){
            k--;
        } 
        
        for(int i = k;i >= 0;i--){ //输出
            cout<<os[i];
        }
        
        cout<<endl;
    }
 return 0;
}
