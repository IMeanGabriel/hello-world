#include <bits/stdc++.h>
using namespace std;

string code = "VWXYZABCDEFGHIJKLMNOPQRSTU";
string str;

int main(void)
{

    //int i;
    while (1)
    {
        getline(cin, str);
        if (str == "ENDOFINPUT")
            break;
        getline(cin, str);
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = code[str[i] - 'A'];
            }
            // else
            // {
            //     cout << str[i];
            // }
        }
        cout << str;
        cout << endl;
        getline(cin, str);
    }
    return 0;
}



