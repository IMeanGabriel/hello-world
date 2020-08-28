#include<bits/stdc++.h>
using namespace std;

char *country[100];

int main()
{
    int n;
    scanf("%d", &n);
    int i = 0, j;


    while (i < n)
    {
        country[i] = (char *)malloc(20);
        scanf("%s", country[i++]);
    }
    char target[] = "China";
    char *p = target;
    for (i = 0; i < n - 1; i++)
    {
        if ((*country[i]) == (*p))
        {
            for (j = i; j < n - 1; j++)
            {
                country[j] = country[j + 1];
            }
        }
    }
    char *t;
    for (i = 0; i < n - 2; i++)
    {
        for (j = 0; j < n - i - 2; j++)
        {
            if (strcmp(country[j], country[j + 1]) > 0)
            {
                t = country[j];
                country[j] = country[j + 1];
                country[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout<<country[i]<<endl;
    }
    cout<<"China"<<endl;
    return 0;
}