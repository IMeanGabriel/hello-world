
#include<iostream>
#include<string>
using namespace std;


bool compare(string S,char * ch,int number,int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(ch[i]==S[number])
        {
            return false;
            break;
        }
        else
        {
            continue;
        }
    }
    if(i==length)
    {
        return true;
    }
}
void print(char * ch,int * num,int count);
void statistics_print(string S,char * ch,int * num)
{
    int length_ch=0;
    int length_S=S.length();
    int count=1;
    for(int i=0;i<length_S;i++)
    {
        if(i==0 || compare(S,ch,i,length_ch))
        {
            ch[length_ch]=S[i];
            for(int j=0;j<length_S;j++)
            {
                if(i!=j && S[i]==S[j])
                    count++;
            }
            num[length_ch]=count;
            length_ch++;
            count=1;
        }


    }
    print(ch,num,length_ch);
}

void print(char * ch,int * num,int count)
{
    for(int i=0;i<count;i++)
    {
        cout<<"i:"<<ch[i]<<",number: "<<num[i]<<endl;
    }
}

int main()
{
    string S="ABACDDEC912ED8809";
    char ch[20];
    int num[20];
    statistics_print(S,ch,num);
    return 0;
}
