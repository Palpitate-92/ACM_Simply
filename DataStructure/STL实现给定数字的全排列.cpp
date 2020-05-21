#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, a[10];
    while ((scanf("%d", &n)) == 1)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        //sort(a, a + n);
        do
        {
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
            puts("");
        } while (next_permutation(a, a + n));
        puts("");
    }
    return 0;
}