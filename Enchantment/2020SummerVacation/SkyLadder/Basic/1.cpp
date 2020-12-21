// #include<bits/stdc++.h>
// using namespace std;
// double a[10004];
// int main()
// {
//     int n;
//     double ans=0.0;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         scanf("%lf",&a[i]);
//         ans+=(double)(1.0/a[i]);
//     }
//     ans=(double)(ans/n);
//     ans=(double)(1.0/ans);
//     printf("%.2f\n",ans);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
char model[20]={"chi1 huo3 guo1"};

bool check(char ss[],char model[]){
    for(int i=0;i<14;i++){
        if(ss[i]!=model[i]){
            return false;
        }
    }
    return true;
}

// int main(){
//     string ss;
//     char tmp[30];
//     cout<<model<<endl;
//     int g=0;
//     while(scanf("%c",&tmp[g])!='\n') g++;

//     // for(int i=0;i<sizeof(tmp);i++){
//     //     printf("%c",tmp[i]);
//     // }
//     for(int j=0;j<g;j++){
//         printf("%c",tmp[j]);
//     }
//     printf("\n");
//     cin>>ss;
//     int flg=0;
//     while(ss[0]!='.'){
//         n++;
//         cout<<n<<endl;
//         //cout<<"@@@"<<endl;
//         
//             }
//         }
//     cin>>ss;
//     }
//     printf("%d\n",n);
//     if(flg==1){
//         printf("%d %d\n",index,cnt);
//     }
//     else{
//         printf("-_-#\n");
//     }
// }

// int main(){
//     char ss[100];    int flg=0;
//     int cnt=0,index=1000,n=0;
//     //scanf("%c",&ss[0]);

//     int j=0;
//     while(ss[j]!='\n'){
//         j++;
//         scanf("%c",&ss[j]);
//     }
//     while(ss[0]!='.'){

//     // for(int i=0;i<=j;i++){
//     //     if(ss[i]=='c'){
//     //         if(check(ss,model)){
//     //                 flg=1;
//     //                 cnt++;
//     //                 index=min(index,i);
//     //                 break;            
//     //         }
//     //     }
//     // }


//     // }
//     // if(flg==1){
//     //     printf("%d %d\n",index,cnt);
//     // }
//     // else{
//     //     printf("-_-#\n");
//     // }

//     for(int i=0;i<j;i++){
//         printf("%c",ss[i]);
//     }
//     printf("\n");
//     }}
    
int main(){
    printf("5\n");
    printf("-_-#\n");
}