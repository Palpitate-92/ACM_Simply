#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL M = 1e10 + 7;
const int N = 1e5;
LL Num[N + 1];
int main()
{
    void process(int, int);
    int n, q, a, l, r, o, i = 0;
    LL k;
    cin >> n >> q;
    while (n--)
        cin >> Num[++i];
    while (q--)
    {
        cin >> o >> l >> r;
        if (o == 4)
        {
            process(l, r);
            continue;
        }
        cin >> k;
        switch (o)
        {
        case 1:
            for (i = l; i <= r; i++)
                Num[i] += k;
            break;
        case 2:
            for (i = l; i <= r; i++)
                Num[i] *= k;
            break;
        case 3:
            for (i = l; i <= r; i++)
                Num[i] = k;
            break;
        }
    }
    return 0;
}
void process(int l, int r)
{
    LL value = 0, x = 0, temp = 0;
    for (int i = l; i <= r; i++)
        x += Num[i];
    x /= (r - l + 1);
    for (int i = l; i <= r; i++)
    {
        temp = pow(Num[i] - x, 2);
        value += temp;
    }
    value *= (r - l + 1);
    temp = value % M;
    cout << temp << endl;
}