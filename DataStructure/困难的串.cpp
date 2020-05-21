#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, L, cnt, s[N];
int dfs(int cur)
{
    if (cnt == n)
    {
        for (int i = 0; i < cur; i++)
            printf("%c", s[i] + 'A');
        puts("");
        return 1;
    }
    int i, j, k;
    for (i = 0; i < L; i++)
    {
        s[cur] = i;
        for (j = 1; j <= (cur + 1) / 2; j++)
        {
            for (k = 0; k < j; k++)
                if (s[cur - k] != s[cur - k - j])
                    break;
            if (k == j)
                break;
        }
        if (j > (cur + 1) / 2)
        {
            cnt++;
            if (dfs(cur + 1) == 1)
                return 1;
        }
    }
    return 0;
}
int main()
{
    while ((scanf("%d%d", &n, &L)) == 2)
    {
        cnt = 0;
        dfs(0);
    }
    return 0;
}