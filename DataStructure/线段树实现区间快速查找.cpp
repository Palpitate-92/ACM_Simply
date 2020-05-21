#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define tl(x) 2 * x
#define tr(x) 2 * x + 1
const int NMAX = 2e5;
LL num[NMAX + 10];
struct Node
{
    int left, right;
    LL sum;
} rt[NMAX << 2];
void build(int x, int L, int R)
{
    rt[x].left = L;
    rt[x].right = R; //储存区间的两个端点
    if (L == R)
    {
        rt[x].sum = num[L];
        return;
    }
    int mid = (L + R) >> 1;
    build(tl(x), L, mid);
    build(tr(x), mid + 1, R);
    rt[x].sum = rt[tl(x)].sum + rt[tr(x)].sum;
}
int qury(int x, int L, int R)
{
    if (rt[x].left == L && rt[x].right == R)
        return rt[x].sum;
    int mid = (rt[x].left+rt[x].right) >> 1;
    if (R <= mid)
        return qury(tl(x), L, R);
    else if (L > mid)
        return qury(tr(x), L, R);
    else
        return qury(tl(x), L, mid) + qury(tr(x), mid + 1, R);
}
int main()
{
    LL n, k, i = 1, j, kinds = 0, kinds_all, Gcd;
    scanf("%lld%lld", &n, &k);
    while (i <= n)
        scanf("%lld", &num[i++]);
    build(1, 1, n);
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            if (qury(1, i, j) <= k * (j - i + 1))
                kinds++;
    if (kinds == 0)
        printf("0/1");
    else
    {
        kinds_all = (n + 1) * n / 2;
        Gcd = gcd(kinds, kinds_all);
        printf("%lld/%lld", kinds / Gcd, kinds_all / Gcd);
    }
    return 0;
}