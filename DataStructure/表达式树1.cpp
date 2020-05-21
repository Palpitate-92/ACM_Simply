#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int Lch_ex[N];
char Expr[N];
int Rch_ex[N];
int cnt = 0;
int build_tree(char *str, int x, int y)
{
    int c1 = -1, c2 = -1, i, pare = 0, u;
    if (y - x == 1)
    {
        u = cnt++;
        Expr[u] = str[x];
        Lch_ex[u] = Rch_ex[u] = -1;
        return u;//cnt是全局变量所以不能返回cnt的值
    }
    for (i = x; i < y; i++)
        switch (str[i])
        {
        case '(':
            pare++;
            break;
        case ')':
            pare--;
            break;
        case '+':
        case '-':
            if (pare == 0)
                c1 = i;
            break;
        case '*':
        case '/':
            if (pare == 0)
                c2 = i;
            break;
        }
    if (c1 == -1)
        c1 = c2;
    if (c1 == -1)
        return build_tree(str, x + 1, y - 1);
    u=cnt++;
    Expr[u] = str[c1];
    Lch_ex[u] = build_tree(str, x, c1);
    Rch_ex[u] = build_tree(str, c1 + 1, y);
    return u;
}
void middfs(int u)
{
    if (u == -1)
        return;
    printf("(");
    middfs(Lch_ex[u]);
    printf("%c", Expr[u]);
    middfs(Rch_ex[u]);
    printf(")");
}
int main()
{
    char str[N];
    cin >> str;
    build_tree(str, 0, strlen(str));
    middfs(0);
    return 0;
}