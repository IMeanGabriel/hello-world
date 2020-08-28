 #include<bits/stdc++.h>
 using namespace std;

//  int main()
//  {
//      int n;
//      while(cin>>n)
//      {
//          int ans=0;
//          int j,x,y;
//         int f[100][100];
//          for(int i=n;i<=n;i++)
//          {
//             scanf("%d",&f[i]);
//          }
//          if (n==1)  
//     {  
//         cout<<1<<endl;  
//         return 0;  
//     }  
//     memset(f,0,sizeof(f));  
//     f[0][1]=1;  
//     for (int i=2; i<=n; i++)  
//     {  
//         for (int j=1; j<=i; j++) f[y][j]=(f[y][j-1]+f[x][i-j+1]);  
//         swap(x,y);  
//     }  
//     for (int i=1; i<=n; i++) ans=(ans+f[x][i]);  
//     ans=(ans*2);  

//      }    cout<<ans<<endl;

//  }

int num[10006];

 int solve(int num[],int n)
{
        // int len = num.length;
        if (n <= 1)
        {
            return n;
        }
        int cnt1 = 1;
        int cnt2 = 1;
        for (int i = 1; i <= n; i++) 
        {
            if (num[i] > num[i - 1])
            {
                cnt2 = cnt1 +1;
            }
            else if (num[i] < num[i - 1])
            {
                cnt1 = cnt2 + 1;
            }
        }
        return max(cnt1,cnt2);
    }


int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
        }
        cout<<solve(num,n)<<endl;
    }
    return 0;
}
