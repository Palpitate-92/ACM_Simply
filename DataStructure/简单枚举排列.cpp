#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 5; j++)
        {
            if (j == i)
                continue;
            for (int k = 1; k < 5; k++)
            {
                if (k == j || k == i)
                    continue;
                for (int l = 1; l < 5; l++)
                {
                    if (l == k || l == j || l == i)
                        continue;
                    printf("%d %d %d %d\n", i, j, k, l);
                    break;
                }
            }
        }
    return 0;
}