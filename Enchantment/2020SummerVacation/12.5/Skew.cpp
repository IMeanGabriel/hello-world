#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string ss;
    while(cin>>ss&&ss[0]!='0'){
        int ans=0;
        for(int i=ss.length();i>=0;i--){
            ans+=(ss[ss.length()-i]-'0')*(pow(2,i)-1);
        }
        cout<<ans<<endl;
    }
}