#include <bits/stdc++.h>
using namespace std;
const int N1 = 362880;
const int N2 = 1e6;
int s[9], g[9], fact[9], Queue[N2][9], vis[N1], dist[N2];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int encode(int cur)
{
    int i, j, cnt, code = 0;
    for (i = 0; i < 9; i++)
    {
        cnt = 0;
        for (j = i - 1; j >= 0; j--)
            if (Queue[cur][i] > Queue[cur][j])
                cnt++;
        code += fact[i] * cnt;
    }
    return code;
}
int bfs(void)
{
    int front = 0, rear = 1, *pf, *pr, code;
    int i, x, y, z, newx, newy, newz;
    memcpy(Queue[front], s, sizeof(s));
    vis[encode(0)] = 1;
    dist[front] = 0;
    while (front < rear)
    {
        pf = Queue[front];
        if (memcmp(pf, g, sizeof(g)) == 0)
            return front;
        for (z = 0; z < 9; z++)
            if (pf[z] == 0)
                break;
        x = z / 3;
        y = z % 3;
        for (i = 0; i < 4; i++)
        {
            newx = x + dx[i];
            newy = y + dy[i];
            newz = newx * 3 + newy;
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                pr = Queue[rear];
                memcpy(pr, pf, sizeof(g));
                pr[z] = pf[newz];
                pr[newz] = pf[z];
                dist[rear] = dist[front] + 1;
                code = encode(rear);
                if (vis[code] == 0)
                {
                    vis[code] = 1;
                    rear++;
                }
            }
        }
        front++;
    }
    return 0;
}
int main()
{
    int i, ans, T;
    for (i = 1, fact[0] = 1; i < 9; i++)
        fact[i] = fact[i - 1] * i;
    scanf("%d", &T);
    while (T--)
    {
        for (i = 0; i < 9; i++)
            scanf("%d", &s[i]);
        for (i = 0; i < 9; i++)
            scanf("%d", &g[i]);
        memset(vis, 0, sizeof(vis));
        ans = bfs();
        if (ans > 0)
            printf("%d\n", dist[ans]);
        else
            printf("-1\n");
    }
    return 0;
}