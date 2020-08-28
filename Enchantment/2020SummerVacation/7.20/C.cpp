// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std; 
// vector<int> v;

// bool judge()
// {
// 	for(int i=0,j=v.size()-1;i<j;i++,j--)
// 		if(v[i]!=v[j])
//             return false;
// 	return true;
// }
 
// void step(int n,string m)
// {
// 	for(int i=0;i<m.length();i++)
//     {
// 		if(isupper(m[i]))
// 			v.push_back(m[i]-'A'+10);
// 		else
// 			v.push_back(m[i]-'0');
// 	}
// 	for(int i=0;i<=30;i++)
//     {
// 		if(judge()){
// 			cout<<"STEP="<<i<<endl;
// 			return ;
// 		}
// 		vector<int> sum;
// 		sum.clear();
// 		int mod=0;
// 		for(int j=0,size=v.size();j<size;j++){
// 			int x=v[j]+v[size-j-1]+mod;
// 			mod=x/n;
// 			sum.push_back(x%n);
// 		}
// 		if(mod) sum.push_back(mod);
// 		v.assign(sum.rbegin(),sum.rend());
// 	}
// 	cout<<"Impossible!"<<endl;
// }
 
 
// int main() {
// 	int n;
// 	string m;
// 	cin>>n>>m;
// 	step(n,m);	
// 	return 0;
// }

#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

bool Huiwen(string s)
{
	for(int i=0,j=s.length()-1;i<j;i++,j--)
		if(s[i]!=s[j])
            return false;
	return true;
}


void Judge(int n, string m, int k)
{
	if (k > 30)
	{
		cout << "Impossible!" << endl;
		return;
	}
	if (Huiwen(m))
		cout << "STEP=" << k << endl;
	else
	{
		string s;
		int i = 0, j = m.length() - 1, t = 0;
		while (i <m.length())
		{
			int a, b;
			if (isupper(m[i]))
				a = (m[i] - 'A') + 10;
			else
				a = (m[i] - '0');
 
			if (isupper(m[j]))
				b = (m[j] - 'A') + 10;
			else
				b = (m[j] - '0');
 
			char c;
			if ((a + b + t) % n < 10)
				c = (a + b + t) % n + '0';
			else
				c = (a + b + t) % n - 10 + 'A';
 
			s = c + s;
			t = (a + b + t) / n;
			i++;
			j--;
		}
		char c = t + '0';
		if (t!=0)
            s = c + s;
		Judge(n, s, k + 1);
	}
}


int main()
{
	int n;
	string m;
	cin >> n >> m;
	Judge(n, m, 0);
	return 0;
}