#include <bits/stdc++.h>
using namespace std;
string A, B, C;
int lena, lenb, lenc;
int a[3], b[3];
bool flag;
void check()
{
    int x = a[0] + a[1] * 10 + a[2] * 100;
    int y = b[0] + b[1] * 10 + b[2] * 100;
    int z = x * y;
    for (int i = 0; i < lenc - 1; i++)
    {
        if (C[i] == '*')
        {
            z /= 10;
            continue;
        }
        if ((z % 10 + '0') != C[i])
            return;
        z /= 10;
    }
    if ((z == 0 && C[lenc - 1] != '0') || z >= 10)
        return;
    if (z == C[lenc - 1] - '0' || C[lenc - 1] == '*')
        flag = true;
}
void dfs1(int cur)
{
    if (flag)
        return;
    if (cur == lenb)
    {
        check();
        return;
    }
    if (B[cur] == '*')
    {
        for (int i = (cur == lenb - 1); i <= 9; i++)
        {
            b[cur] = i;
            dfs1(cur + 1);
        }
    }
    else
    {
        b[cur] = B[cur] - '0';
        dfs1(cur +1);
    }
}
void dfs(int cur)
{
    if (flag)
        return;
    if (cur == lena)
    {
        dfs1(0);
        return;
    }
    if (A[cur] == '*')
    {
        for (int i = (cur == lena - 1); i <= 9; i++)
        {
            a[cur] = i;
            dfs(cur + 1);
        }
    }
    else
    {
        a[cur] = A[cur] - '0';
        dfs(cur + 1);
    }
}
int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
    {
        cin >> A >> B >> C;
        lena = A.length();
        lenb = B.length();
        lenc = C.length();
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        reverse(C.begin(), C.end());
        for (int i = 0; i < 3; i++)
            a[i] = 0, b[i] = 0;
        flag = false;
        dfs(0);
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}