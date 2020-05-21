#include <bits/stdc++.h>
using namespace std;
#define M 5
#define N 4
int sr, sc, counter, flag, visited[M + 1][N + 1];
//int d[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2}, {-1, -2, -2, -1, 1, 2, 2, 1}};
int d[2][8] = {{-1, -1, -2, -2, 2, 2, 1, 1}, {2, -2, 1, -1, 1, -1, 2, -2}};
void dfs(int row, int col)
{
    if (flag != 0 && row == sr && col == sc)
        counter++;
    else
    {
        int pr, pc;
        flag = 1;
        for (int i = 0; i < 8; i++)
        {
            pr = row + d[0][i];
            pc = col + d[1][i];
            if (pr >= 1 && pr <= M && pc >= 1 && pc <= N && visited[pr][pc] == 0)
            {
                visited[pr][pc] = 1;
                dfs(pr, pc);
                visited[pr][pc] = 0;
            }
        }
    }
}
int main()
{
    while ((scanf("%d%d", &sr, &sc)) == 2)
    {
        counter = 0;
        flag = 0;
        memset(visited, 0, sizeof(visited));
        dfs(sr, sc);
        printf("%d\n", counter);
    }
    return 0;
}