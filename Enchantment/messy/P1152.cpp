// #include <bits/stdc++.h>
// using namespace std;

// map<string, float> str;

// void Init(void);

// int main()
// {
//     str["UTC"] = 0;
//     str["GMT"] = 0;
//     str["BST"] = 2;
//     str["IST"] = 2;
//     str["WET"] = 0;
//     str["WEST"] = 2;
//     str["CET"] = 2;
//     str["CEST"] = 4;
//     str["EET"] = 4;
//     str["EEST"] = 6;
//     str["MSK"] = 6;
//     str["MSD"] = 8;
//     str["AST"] = -8;
//     str["ADT"] = -6;
//     str["NST"] = -7;
//     str["NDT"] = -5;
//     str["EST"] = -10;
//     str["EDT"] = -8;
//     str["CST"] = -12;
//     str["CDT"] = -10;
//     str["MST"] = -14;
//     str["MDT"] = -12;
//     str["PST"] = -16;
//     str["PDT"] = -14;
//     str["HST"] = -20;
//     str["AKST"] = -18;
//     str["AKDT"] = -16;
//     str["AEST"] = 20;
//     str["AEDT"] = 22;
//     str["ACST"] = 19;
//     str["ACDT"] = 21;
//     str["AWST"] = 16;
//     int H, M, n, start, itime;
//     string time, s1, s2;
//     bool t12;
//     bool now;
//     cin >> n;
//     getline(cin, time);
//     for (; n--;)
//     {
//         start = H = M = 0;
//         s1.clear();
//         s2.clear();
//         now = true;
//         getline(cin, time);
//         if (time.length() > 4 && time.substr(0, 4) == string("noon"))
//         {
//             t12 = false;
//             H = 12;
//             start = 5;
//         }
//         else if (time.length() > 8 && time.substr(0, 8) == string("midnight"))
//         {
//             t12 = true;
//             H = 12;
//             start = 9;
//         }
//         else
//         {
//             for (int i = 0; i < time.length(); i++)
//             {
//                 if (time[i] == ':')
//                 {
//                     now = false;
//                     continue;
//                 }
//                 if (time[i] == ' ')
//                 {
//                     start = i + 1;
//                     break;
//                 }
//                 if (now)
//                 {
//                     H *= 10;
//                     H += time[i] - '0';
//                 }
//                 else
//                 {
//                     M *= 10;
//                     M += time[i] - '0';
//                 }
//             }
//             t12 = (time.substr(start, 4) == string("a.m."));
//             if (H == 12)
//                 t12 = !t12;
//             start += 5;
//         }
//         now = true;
//         for (int i = start; i < time.length(); i++)
//         {
//             if (time[i] == ' ')
//             {
//                 now = false;
//                 continue;
//             }
//             if (now)
//             {
//                 s1 += time[i];
//             }
//             else
//             {
//                 s2 += time[i];
//             }
//         }

//         itime = str[s2] - str[s1];
//         if (itime % 2)
//         {
//             H += int(floor(itime / 2));
//             M += 30;
//             if (M >= 60)
//             {
//                 M -= 60;
//                 H += 1;
//             }
//         }
//         else
//         {
//             H += itime / 2;
//         }
//         if (H > 12)
//         {
//             H -= 12;
//             t12 = !t12;
//         }
//         else if (H <= 0)
//         {
//             H += 12;
//             t12 = !t12;
//         }
//         else if (H == 12)
//         {
//             t12 = !t12;
//         }

//         if (H == 12 && !M)
//         {
//             cout << (t12 ? "midnight" : "noon") << endl;
//         }
//         else
//         {
//             cout << H << ':' << M << ' ' << (t12 ? "a.m." : "p.m.") << endl;
//         }
//     }
//     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// int standard(char *zone1, char *zone2)
// {
// 	char zone[32][7]= {"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
// 	double time[32] = { 0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8 };
// 	int i, j;
// 	for (i = 0; strcmp(zone[i], zone1)!=0; i++);
// 	for (j = 0; strcmp(zone[j], zone2)!=0; j++);
// 	return (int)((time[i] - time[j]) * 60);
// }

// int main()
// {
// 	int n;
//     while(scanf("%d",&n)!=EOF)
// {	
// 	while (n--)
//     {
// 		char time[9];
// 		int h, m;
// 		scanf("%s", time);
// 		switch (time[0])
//         {
// 		case'n':
// 			h = 12;
// 			m = 0;
// 			break;
// 		case'm':
// 			h = 0;
// 			m = 0;
// 			break;
// 		default:
// 			sscanf(time, "%d:%d", &h, &m);
// 			h %= 12;
// 			scanf("%s", time);
// 			if (time[0] == 'p')
// 				h += 12;
// 		}
// 		char str1[7], str2[7];
// 		scanf("%s %s", str1, str2);
// 		int newtime = h * 60 + m + standard(str2, str1);
// 		if (newtime < 0)
// 			newtime += 1440;
// 		newtime %= 1440;
// 		switch (newtime)
//         {
// 		case 0 :
// 			printf("midnight\n");
//             break;
// 		case 720:
// 			printf("noon\n");
//             break;
// 		default:
// 			h = newtime / 60;
// 			m = newtime % 60;
// 			if (h == 0)
// 				printf("12:%02d a.m.\n", m);
// 			else if (h < 12)
// 				printf("%d:%02d a.m.\n", h, m);
// 			else if (h == 12)
// 				printf("12:%02d p.m.\n", m);
// 			else if (h > 12)
// 				printf("%d:%02d p.m.\n", h%12, m);
// 		}
//         }
// 	}
// 	return 0;
// }

// TSOJ-1152 时区间时间的转换
// TSOJ-1152 时区间时间的转换
// TSOJ-1152 时区间时间的转换
// TSOJ-1152 时区间时间的转换
#include <bits/stdc++.h>
using namespace std;

map<string,float> Timezone;

void Init();

int main()
{
	Timezone["UTC"] = 0;
	Timezone["GMT"] = 0;
	Timezone["BST"] = 2;
	Timezone["IST"] = 2;
	Timezone["WET"] = 0;
	Timezone["WEST"] = 2;
	Timezone["CET"] = 2;
	Timezone["CEST"] = 4;
	Timezone["EET"] = 4;
	Timezone["EEST"] = 6;
	Timezone["MSK"] = 6;
	Timezone["MSD"] = 8;
	Timezone["AST"] = -8;
	Timezone["ADT"] = -6;
	Timezone["NST"] = -7;
	Timezone["NDT"] = -5;
	Timezone["EST"] = -10;
	Timezone["EDT"] = -8;
	Timezone["CST"] = -12;
	Timezone["CDT"] = -10;
	Timezone["MST"] = -14;
	Timezone["MDT"] = -12;
	Timezone["PST"] = -16;
	Timezone["PDT"] = -14;
	Timezone["HST"] = -20;
	Timezone["AKST"] = -18;
	Timezone["AKDT"] = -16;
	Timezone["AEST"] = 20;
	Timezone["AEDT"] = 22;
	Timezone["ACST"] = 19;
	Timezone["ACDT"] = 21;
	Timezone["AWST"] = 16;
	int H,M,n,start,tmp;
	string temp,s1,s2;
	bool t12; // true-a.m. false-p.m.
	bool now;
	cin>>n;
	getline(cin,temp);
	while(n--)
	{
		start = H = M = 0;
		s1.clear();
		s2.clear();
		now = true; // H
		getline(cin,temp);
		if(temp.length()>4 && temp.substr(0,4)==string("noon"))
        {
			t12 = false;
			H = 12;
			start = 5;
		}
		else if(temp.length()>8 && temp.substr(0,8)==string("midnight"))
        {
			t12 = true;
			H = 12;
			start = 9;
		}
        else
        {
			for(int i=0;i<temp.length();i++)
            {
				if(temp[i] == ':')
                {
                    now=false;
                    continue;
                }
				if(temp[i] == ' ')
                {
                    start=i+1;
                    break;
                }
				if(now)
                {
					H *= 10;
					H += temp[i] - '0';
				}
                else
                {
					M *= 10;
					M += temp[i] - '0';
				}
			}
			t12 = (temp.substr(start,4) == string("a.m."));
			if(H==12)
				t12 = !t12;
			start += 5;
		}
		now = true;
		for(int i=start;i<temp.length();i++)
        {
			if(temp[i] == ' ')
            {
                now=false;
                continue;
            }
			if(now)
            {
				s1 += temp[i];
			}
            else
            {
				s2 += temp[i];
			}
		}
		
		tmp = Timezone[s2] - Timezone[s1];
		if(tmp%2)
        {
			H += int(floor(tmp/2));
			M += 30;
			if(M>=60)
            {
				M -= 60;
				H += 1;
			}
		}else
        {
			H += tmp/2;
		}
		if(H>12)
        {
			H -= 12;
			t12 = !t12;
		}
        else if(H<=0)
        {
			H += 12;
			t12 = !t12;
		}
        else if(H == 12)
        {
			t12 = !t12;
		}
		
		if(H==12 && !M)
        {
			cout<<(t12?"midnight":"noon")<<endl;
		}
        else
        {
			cout<<H<<':'<<M<<' '<<(t12?"a.m.":"p.m.")<<endl;
		}
	}
	return 0;
}
