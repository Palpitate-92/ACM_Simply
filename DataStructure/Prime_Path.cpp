#include <bits/stdc++.h>
using namespace std;
struct
{
    int dis = 0;
    bool visited = false;
} Prime[9999];
bool isprime(int x)
{
    for (int i = 2; i <= sqrt((double)x); i++)
        if (x % i == 0)
            return false;
    return true;
}
int bfs(int s, int r)
{
    if (s == r)
        return 0;
    Prime[s].dis = 0;
    Prime[s].visited = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int i = 0; i <= 9; i++)
        {
            int x1 = (top / 10) * 10 + i;
            if (isprime(x1) && !Prime[x1].visited)
            {
                q.push(x1);
                Prime[x1].dis = Prime[top].dis + 1;
                Prime[x1].visited = true;
            }
            int x2 = top % 10 + (top / 100) * 100 + i * 10;
            if (isprime(x2) && !Prime[x2].visited)
            {
                q.push(x2);
                Prime[x2].dis = Prime[top].dis + 1;
                Prime[x2].visited = true;
            }
            int x3 = top % 100 + (top / 1000) * 1000 + i * 100;
            if (isprime(x3) && !Prime[x3].visited)
            {
                q.push(x3);
                Prime[x3].dis = Prime[top].dis + 1;
                Prime[x3].visited = true;
            }
            if (i != 0)
            {
                int x4 = top % 1000 + i * 1000;
                if (isprime(x4) && !Prime[x4].visited)
                {
                    q.push(x4);
                    Prime[x4].dis = Prime[top].dis + 1;
                    Prime[x4].visited = true;
                }
            }
            if (Prime[r].visited)
                return Prime[r].dis;
        }
    }
    return 0;
}
int main()
{
    int n, s, r;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &s, &r);
        memset(Prime, 0, sizeof(Prime));
        printf("%d\n", bfs(s, r));
    }
    return 0;
}