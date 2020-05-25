#include <bits/stdc++.h>
using namespace std;
int house[6][6];
void makehouse()
{
    memset(house, 0, sizeof(house));
    for (int i = 1; i < 6; i++)
        for (int j = 1; j < 6; j++)
            if (i != j)
                house[i][j] = house[j][i] = 1;
    house[4][1] = house[1][4] = 0;
    house[4][2] = house[2][4] = 0;
}
void dfs(int x, int cur, string s)
{
    s += char(x + '0');
    if (cur == 8)
    {
        cout << s << '\n';
        return;
    }
    for (int i = 1; i < 6; i++)
    {
        if (house[x][i])
        {
            house[x][i] = house[i][x] = 0;
            dfs(i, cur + 1, s);
            house[x][i] = house[i][x] = 1;
        }
    }
}
int main()
{
    makehouse();
    dfs(1, 0, "");
    return 0;
}