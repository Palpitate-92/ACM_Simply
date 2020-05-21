#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N], n;
void create(int cur)
{
    int j;
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", a[i]);
        puts("");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (j = 0; j < cur; j++)
                if (a[j] == i)
                    break;
            if (j == cur)
            {
                a[cur] = i;
                create(cur + 1);
            }
        }
    }
}
int main()
{
    //while ((scanf("%d", &n) == 1))
    n = 9;
    freopen("f.out", "w", stdout);
    create(0);
    return 0;
}