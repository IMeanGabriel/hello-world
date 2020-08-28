#include<stdio.h>
#include<string.h>
#define N 100010
#define mod 1000000007
long long int a[N]={1,1,2},ans;
int main()
{
    int T,n;
    int i,j;
    
    for(i=3;i<N;i++)
    a[i]=(a[i-2]+a[i-1])%mod;

    
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        
        int sen[N]={0};
        char word[20],word1[20];
        word[0]=word1[0]='\0';
        for(i=1,j=0;i<=n;i++)
        {
            scanf("%s",word);
            if(strcmp(word,word1)==0)
            {
                j++;
                sen[j]++;
            }
            else
            sen[j]++;
            
            strcpy(word1,word);
        }
        int n1=j+1;
        
        ans=1;
        for(i=0;i<n1;i++)
        ans=(ans*a[sen[i]])%mod;
        
        printf("%d\n",ans);
        
    }
    
    return 0;
} 