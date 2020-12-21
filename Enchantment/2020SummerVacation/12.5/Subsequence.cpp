#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string ss1,ss2;
    while(cin>>ss1>>ss2){
        // int j=0;
        // bool flag=true;
        // for(int i=0;i<ss1.length();i++){
        //     while(ss1[i]!=ss2[j]){
        //         j++;
        //     }
        //     if(ss1[i]==ss2[j]){
        //         j++;
        //     }
        //     if(j==ss2.length()-1){
        //         flag=false;
        //         break;
        //     }
        // }
        int i=0;
        int j=0;
        while(i<ss1.length()&&j<ss2.length()){
            if(ss1[i]==ss2[j]){
                i++;
            }
            j++;
        }
        if(i==ss1.length()){
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        
    }
}
