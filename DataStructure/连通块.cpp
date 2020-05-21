#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int flag[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m, a[N][N], Queue[N * N][2];
bool visited[N][N];
void bfs(int x, int y)
{
    int front = 1, rear = 2;
    Queue[front][0] = x;
    Queue[front][1] = y;
    while (front < rear)
    {
        x = Queue[front][0];
        y = Queue[front++][1];
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + flag[i][0];
            int y1 = y + flag[i][1];
            if (x1 < 1 || x1 > n || y1 < 1 || y1 > m || a[x1][y1] == 0 || visited[x1][y1])
                continue;
            visited[x1][y1] = true;
            Queue[rear][0] = x1;
            Queue[rear++][1] = y1;
        }
    }
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                ans++;
                bfs(i, j);
            }
    printf("%d\n", ans);
    return 0;
}