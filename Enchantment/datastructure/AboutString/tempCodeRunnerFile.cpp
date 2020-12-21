#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int i;
bool Check_Different_Letters(string S,char Letter[],int index,int length)
{

    for(i=0;i<length;i++)
    {
        if(Letter[i]==S[index])
        {
            return true;
        }
    }
	return false;
}

void print(char Letter[],int num[],int cnt)
{
    for(i=0;i<cnt;i++)
    {
        cout<<"Letter "<<Letter[i]<<" has "<<num[i]<<";"<<endl;
    }
}

void OunPut(string S,char Letter[],int num[])
{
    int Len2=0;
    int Len1=S.length();
    for(int i=0;i<Len1;i++)
    {

        if(!Check_Different_Letters(S,Letter,i,Len2))
        {
            Letter[Len2]=S[i];
            for(int j=0;j!=i&&j<Len1;j++)
            {
                if(S[i]==S[j])
                    cnt++;
            }
            num[Len2]=cnt;
            Len2++;cnt=1;

        }


    }
    print(Letter,num,Len2);
}


int main()
{
    string S;
	cin>>S;
    char Letter[20];
    int num[20];
    OunPut(S,Letter,num);
    return 0;
}