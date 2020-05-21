#include <bits/stdc++.h>
using namespace std;
const int N = 20020;
int people[N];
int find(int u) //整个程序的精髓所在......
{
    return (people[u] == u) ? u : (people[u] = find(people[u]));
}
int main()
{
    int n, m, i, a, b, s, t;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        people[i] = i;
    while (m--)
    {
        scanf("%d%d", &a, &b);
        s = find(a);
        t = find(b);
        if (s != t)
            people[t] = s;
    }
    int q, c, d;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &c, &d);
        s = find(c);
        t = find(d);
        if (s == t)
            printf("Yse\n");
        else
            printf("No\n");
    }
    return 0;
}