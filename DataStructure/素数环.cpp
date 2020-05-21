#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, tot, s[N + 1], vis[N + 1], prime[N << 1];
void dfs(int cur)
{
    if (cur == n)
    {
        if (prime[s[0] + s[n - 1]] == 1)
        {
            tot++;
            for (int i = 0; i < n; i++)
                printf("%d ", s[i]);
            puts("");
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if (vis[i - 1] == 0 && prime[s[cur - 1] + i] == 1)
            {
                vis[i - 1] = 1;
                s[cur] = i;
                dfs(cur + 1);
                vis[i - 1] = 0;
            }
    }
}
int main()
{
    int i, j, k;
    for (i = 3; i < (N << 1); i++)
    {
        k = sqrt(i);
        for (j = 2; j <= k; j++)
            if (i % j == 0)
                break;
        if (j > k)
            prime[i] = 1;
    }
    while ((scanf("%d", &n)) == 1)
    {
        tot = 0;
        s[0] = 1;
        vis[0] = 1;
        dfs(1);
        if (tot == 0)
            printf("No solution!\n");
    }
}