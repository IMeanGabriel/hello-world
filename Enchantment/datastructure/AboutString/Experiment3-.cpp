#include <bits/stdc++.h>
using namespace std;
#define ElemType int
#define SElemType int
//#define char char
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR 0
#define OK 1
#define TRUE true
#define FALSE false
#define MAXN 100006

typedef struct
{
	char ch[MAXN];
	ElemType length;
} SString;

ElemType Index(SString str1, SString str2)
{
	ElemType i = 0, j = 0;
	ElemType cnt = 0;
	for (j = 0; j < str1.length; j++)
	{
		for (i = 0; i < str2.length; i++)
		{
			if ((j + i > str1.length - 1) 
				|| (!(str1.ch[j + i] == str2.ch[i])))
			{
				break;
			}
		}
		if (i >= str2.length)
		{
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	SString s, t;
	ElemType ans;
	scanf("%s%s", s.ch, t.ch);
	s.length = strlen(s.ch);
	t.length = strlen(t.ch);
	ans = Index(s, t);
	printf("The times that t appears in s: %d\n", ans);
	return 0;
}






