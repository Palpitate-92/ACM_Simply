#include <bits/stdc++.h>
using namespace std;
int a[10], n;
void creat_subset(int cur)
{
    for (int i = 0; i < n; i++)
    {
        if (cur & (1 << i))
            printf("%d ", a[i]);
    }
    puts("");
}
int main()
{
    while ((scanf("%d", &n)) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < (1 << n); i++)
            creat_subset(i);
    }
    return 0;
}