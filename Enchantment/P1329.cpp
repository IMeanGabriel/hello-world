#include <bits/stdc++.h>
using namespace std;

	int symbolyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int specialyear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };


bool checkyear(int year)//是否是闰年
{
	if ((year % 100 == 0 && year % 400 == 0) ||(year % 4 == 0 && year % 100 != 0) )
	{
		return true;
	}
	else return false;
}
int checkmonth(int nowday[],int n)//计算当月之前的天数
{
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		tot += nowday[i];
	}
	return tot;
}
int findfrinowday(int nowday)//计算每个月加上13天后应该余多少天得到星期五
{
	if (nowday == 6)
    return 6;
	else if (nowday == 7)return 5;
	else return 5 - nowday;
}

int main()
{
	int n;
	while(cin >> n)
{
		int cnt = 0;
	int nowday = 0;
    for (int i = 1998; i < n; i++)
	{
		if (checkyear(i))
		{
			nowday += 366;
		}
		else nowday += 365;
	}
	int firstnowday = (nowday + 4) % 7;

	for (int i = 0; i < 12; i++)
	{
		if (checkyear(n))
		{
			if ((checkmonth(specialyear, i) + 12) % 7 == findfrinowday(firstnowday))
				cnt++;
		}
		    else
                if ((checkmonth(symbolyear, i) + 12) % 7 == findfrinowday(firstnowday))
				    cnt++;
        }
	
	cout <<n<<" "<< cnt<<endl;
	}	return 0;
}