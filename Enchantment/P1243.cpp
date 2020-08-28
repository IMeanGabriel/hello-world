// #include <bits/stdc++.h>
// using namespace std;

// struct node{
//     int index;
//     char country[20];
//     int num;
//     char continent[20];
// };

// int main()
// {
//     struct node team[100];
//     struct node temp;
//     int n;
//     while(scanf("%d",&n)!=EOF)
//     {
//         for(int i=0;i<n;i++)
//             scanf("%d %s %d %s",&team[i].index,
//                                     &team[i].country,
//                                     &team[i].num,
//                                     &team[i].continent);
//         for(int i=0;i<n-1;i++)
//         {
//         for(int j=i;j<n-1;j++)
//         {
//         if(strcmp(team[i].country,team[j].country)>0)
//             {
//                 temp =  team[i];
//                 team[i] = team[j];
//                 team[j] = temp;
//             }
//         }
//         }
//         int mark;
//         for(int i=0;i<n;i++)
//         {
//             if(strcmp(team[i].country,"China")==0)
//             {
//                 mark=i;
//                 continue;
//             }

//             printf("%d %s %d %s\r\n",team[i].index,
//                                     team[i].country,
//                                     team[i].num,
//                                     team[i].continent);
//         }
//          printf("%d %s %d %s\r\n",team[mark].index,
//                                     team[mark].country,
//                                     team[mark].num,
//                                     team[mark].continent);

//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct node{
    int index;
    char country[20];
    int num;
    char continent[20];
};

int main()
{
    struct node team[100];
    struct node temp;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%s%d%s",&team[i].index,
                                    &team[i].country,
                                    &team[i].num,
                                    &team[i].continent);
        for(int i=0;i<n-1;i++)
        {
        for(int j=0;j<n-i-1;j++)
        {
        if(strcmp(team[j].country,team[j+1].country)>0)
            {
                temp =  team[j];
                team[j] = team[j+1];
                team[j+1] = temp;
            }
        }
        }
        int mark;
        for(int i=0;i<n;i++)
        {
            if(strcmp(team[i].country,"China")==0)
            {
                mark=i;
                continue;
            }

            printf("%d %s %d %s\r\n",team[i].index,
                                    team[i].country,
                                    team[i].num,
                                    team[i].continent);
        }
         printf("%d %s %d %s\r\n",team[mark].index,
                                    team[mark].country,
                                    team[mark].num,
                                    team[mark].continent);

    }

    return 0;
}
