#include<bits/stdc++.h>
using namespace std;
int m[100]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};

int main(){
    int a[4][4];
    int flg[20]={0};
    int x,y;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
            flg[a[i][j]]=1;
        }
    }

    for(int k=1;k<=3;k++){
        scanf("%d%d",&x,&y);
        cout<<a[x][y]<<endl;
    }

    int index;
    for(int i=1;i<=9;i++){
        if(flg[i]==0){
            index=i;
        }
    }
    //cout<<"                                "<<index<<endl;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(a[i][j]==0)
                a[i][j]=index;
        }
    }
    int type;
    int sum=0;
    scanf("%d",&type);
    if(type<=3){
        for(int i=1;i<=3;i++){
            sum+=a[type][i];
        }
    }

    else if(type>=4&&type<=6){
        for(int i=1;i<=3;i++){
            sum+=a[i][type-3];
        }
    }

    else if(type==7){
        for(int i=1;i<=3;i++){
            sum+=a[i][i];
        }
    }

    else{
        for(int i=1;i<=3;i++){
            sum+=a[i][3-i+1];
        }
    }
    
    cout<<m[sum]<<endl;
}

