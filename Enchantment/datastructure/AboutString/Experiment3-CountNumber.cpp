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
            return false;
        }
    }
	return true;
}

void print(char Letter[],int num[],int cnt)
{
    for(i=0;i<cnt;i++)
    {
        cout<<"Element:"<<Letter[i]<<" appears "<<num[i]<<";"<<endl;
    }
}

void Output(string S,char Letter[],int num[])
{
    int Len2=0;
    int Len1=S.length();
    //printf("%d\n",Len1);
    int cnt=1;
    for(int i=0;i<Len1;i++)
    {

        if(Check_Different_Letters(S,Letter,i,Len2))
        {
            Letter[Len2]=S[i];
            for(int j=0;j<Len1;j++)
            {
                if(i!=j&&S[i]==S[j])
                    cnt++;
            }
            num[Len2]=cnt;
            Len2++;
            cnt=1;

        }


    }
    //printf("%d\n",Len2);
    print(Letter,num,Len2);
}


int main()
{
    string S;
	cin>>S;
    char Letter[20];
    int num[20];
    Output(S,Letter,num);
    return 0;
}
