#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ss;
    while(cin>>ss)
    {
        int len=ss.length();
        for(int i=0;i<len;i++)
        {
            if(ss[i]>='a'&&ss[i]<='z')
                ss[i]=toupper(ss[i]);
        }
        for(int i=0;i<len;i++)
        {
            switch(ss[i])
            {
                case 'A':
                    cout<<".-";
                    break;
                case 'B':
                    cout<<"-...";
                    break;
                    case 'C':
                        cout << "-.-.";
                        break;
                case 'D':
                    cout<<"-..";
                    break;
                case 'E':
                    cout<<".";
                    break;
                case 'F':
                    cout<<"..-.";
                    break;
                case 'G':
                    cout<<"--.";
                    break;
                case 'H':
                    cout<<"....";
                    break;
                case 'I':
                    cout<<"..";
                    break;
                case 'J':
                    cout<<".---";
                    break;
                case 'K':
                    cout<<"-.-";
                    break;
                case 'L':
                    cout<<".-..";
                    break;
                case 'M':
                    cout<<"--";
                    break;
                case 'N':
                    cout<<"-.";
                    break;
                case 'O':
                    cout<<"---";
                    break;
            case 'P':
                cout << ".--.";
                break;
                case 'Q':
                    cout<<"--.-";
                    break;
                case 'R':
                    cout<<".-.";
                    break;
                case 'S':
                    cout<<"...";
                    break;
                case 'T':
                    cout<<"-";
                    break;
                case 'U':
                    cout<<"..-";
                    break;
                case 'V':
                    cout<<"...-";
                    break;
                case 'W':
                    cout<<".--";
                    break;
                case 'X':
                    cout<<"-..-";
                    break;
                case 'Y':
                    cout<<"-.--";
                    break;
            case 'Z':
                cout << "--..";
                break;
                case '0':
                    cout<<".----";
                    break;
                case '1':
                    cout<<"..---";
                    break;
                case '2':
                    cout<<"...--";
                    break;
                case '3':
                    cout<<"....-";
                    break;
                case '4':
                    cout<<".....";
                    break;
                case '5':
                    cout<<"-....";
                    break;
                case '6':
                    cout<<"--...";
                    break;
                case '7':
                    cout<<"---..";
                    break;
                case '8':
                    cout<<"----.";
                    break;
                case '9':
                    cout<<"-----";
                    break;

            }
            if(i<len-1)
                cout<<"===";
        }
        cout<<endl;
    }
    return 0;
}

// int main()
// {
//     char ss[100];
//     while (cin >> ss)
//     {
//         int i;
//         for (i = 0; ss[i] != '\0'; i++)
//         {
//             if (i > 0)
//             {
//                 cout << "===";
//             }
//             switch (ss[i])
//             {
//             case 'A':
//                 cout << ".-";
//                 break;
//             case 'B':
//                 cout << "-...";
//                 break;
//             case 'C':
//                 cout << "-.-.";
//                 break;
//             case 'D':
//                 cout << "-..";
//                 break;
//             case 'E':
//                 cout << ".";
//                 break;
//             case 'F':
//                 cout << "..-.";
//                 break;
//             case 'G':
//                 cout << "--.";
//                 break;
//             case 'H':
//                 cout << "....";
//                 break;
//             case 'I':
//                 cout << "..";
//                 break;
//             case 'J':
//                 cout << ".---";
//                 break;
//             case 'K':
//                 cout << "-.-";
//                 break;
//             case 'L':
//                 cout << ".-..";
//                 break;
//             case 'M':
//                 cout << "--";
//                 break;
//             case 'N':
//                 cout << "-.";
//                 break;
//             case 'O':
//                 cout << "---";
//                 break;
//             case 'P':
//                 cout << ".--.";
//                 break;
//             case 'Q':
//                 cout << "--.-";
//                 break;
//             case 'R':
//                 cout << ".-.";
//                 break;
//             case 'S':
//                 cout << "...";
//                 break;
//             case 'T':
//                 cout << "-";
//                 break;
//             case 'U':
//                 cout << "..-";
//                 break;
//             case 'V':
//                 cout << "...-";
//                 break;
//             case 'W':
//                 cout << ".--";
//                 break;
//             case 'X':
//                 cout << "-..-";
//                 break;
//             case 'Y':
//                 cout << "-.--";
//                 break;
//             case 'Z':
//                 cout << "--..";
//                 break;
//             case '0':
//                 cout << ".----";
//                 break;
//             case '1':
//                 cout << "..---";
//                 break;
//             case '2':
//                 cout << "...--";
//                 break;
//             case '3':
//                 cout << "....-";
//                 break;
//             case '4':
//                 cout << ".....";
//                 break;
//             case '5':
//                 cout << "-....";
//                 break;
//             case '6':
//                 cout << "--...";
//                 break;
//             case '7':
//                 cout << "---..";
//                 break;
//             case '8':
//                 cout << "----.";
//                 break;
//             case '9':
//                 cout << "-----";
//                 break;
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }
