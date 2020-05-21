#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n;
void bfs()
{
    LL top;
    queue<LL> q;
    q.push(1);
    while (!q.empty())
    {
        top = q.front();
        q.pop();
        if (top % n == 0)
            break;
        q.push(top * 10);
        q.push(top * 10 + 1);
    }
    printf("%lld\n", top);
}
int main()
{
    freopen("f1.out", "w", stdout);
    while (scanf("%d", &n) && n)
        bfs();
    return 0;
}