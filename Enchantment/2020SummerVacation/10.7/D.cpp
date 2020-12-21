

// #include<bits/stdc++.h>
 
// using namespace std;
 
// long long C(int n, int m)
// {
//     long long s=1;
//     if(n < m)
//         s=0;
//     else if (n == m || m == 0)
//         s=1;
//     else
//         for(int i=1; i<=m; i++)
//             s = s * (n - i + 1) / i;
 
//      return s;
//  }
 
// int main(){
//     int n;
//     while(cin>>n){
//         cout<<C(n,4)+C(n,2)+1<<endl;
//     }
//     return 0;
// }

//ans(n=j)-ans(n=1)=ans-1
//=sum (2<=i<=j,i=2k,k∈Z) (i/2-1)j^2+(-i^2/2+i/2+3)j+3/4*i^2-4i+2
//=1/4(-2+j')(j'/2)*j^2+[-1/3(j'/2)(j'/2+1)(j'+1)+1/4(j'+14)(j'/2)]*j+[1/2(j'/2)(j'/2+1)(j'+1)-2(1+j')(j'/2),
//	j'<=j,j'=max{2k,k∈Z}  
//j→n,j'→n1
//!! a/b%MOD ≠ a%MOD/b 
#include<cstdio>
using namespace std;
const long long MOD=1e9+7;
long long check_divide_2(long long a,long long b){
	if(a%2==0) a=a/2;
	else b=b/2;
	
	a%=MOD,b%=MOD;
	return a*b%MOD;
}
long long check_divide_2(long long a,long long b,long long c){
	if(a%2==0) a=a/2;
	else if(b%2==0) b=b/2;
	else c=c/2;
	
	a%=MOD,b%=MOD,c%=MOD;
	return a*b%MOD*c%MOD;
}
long long check_divide_3(long long a,long long b,long long c){
	if(a%3==0) a=a/3;
	else if(b%3==0) b=b/3;
	else c=c/3;
	
	a%=MOD,b%=MOD,c%=MOD;
	return a*b%MOD*c%MOD;
}
int main(){
	long long T,n;
	scanf("%lld",&T);
	for(long long Case=1;Case<=T;Case++){
		scanf("%lld",&n);
//		n=n%MOD;
		long long n1=n/2*2;
		long long ans1,ans2,ans3;
		ans1=check_divide_2((-2+n1)/2,n1/2);
		ans2=( -check_divide_3(n1/2,n1/2+1,n1+1) + check_divide_2(n1/2,(n1+14)/2) +MOD)%MOD;
		ans3=( check_divide_2(n1/2,n1/2+1,n1+1) - (1+n1)%MOD*(n1%MOD)%MOD +MOD)%MOD;
		
		n=n%MOD;
		long long ans=(( ans1*n%MOD*n%MOD + ans2*n%MOD )%MOD + ans3 +1)%MOD;
		printf("Case #%lld: %lld\n",Case,ans);
		
//		long long ans4=1;
//		for(long long i=2;i<=n1;i+=2){
//			ans4+=(i/2-1)*n*n+(-i*i/2+i/2+3)*n+i*i*3/4-4*i+2;
//			ans4=(ans4+MOD)%MOD; 
//		}
//		printf("%lld\n",ans4);
	
	}
	
	return 0;
}