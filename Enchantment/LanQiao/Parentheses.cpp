#include<bits/stdc++.h>
using namespace std;

string Parenthesis(int n)
{
    Set<String> newRes=new HashSet<String>();
    if(n==1){
        newRes.add("()");
        return newRes;
    }
    Set<String> res=Parenthesis(n-1);
    for (String s:res) {
        for (int i = 0; i <s.length() ; i++) {
            if(s.charAt(i)=='('){
                newRes.add(s.substring(0,i+1)+"()"+s.substring(i+1,s.length()));
            }
            newRes.add("()"+s);
        }
    }
    return newRes;
}

string generateParenthesis(int n)
{
    string res=Parenthesis(n);
    string list=new LinkedList<String>();
    for (String s:res) {
        list.add(s);
    }
    return list;
}

int main()
{



}