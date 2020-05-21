#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Queue[] = {2, 6, 4, 1, 3, 7, 0, 5, 8}, fact[9];
    int i, j, cnt, code = 0;
    for (i = 1, fact[0] = 1; i < 9; i++)
        fact[i] = fact[i - 1] * i;
    for (i = 0; i < 9; i++)
    {
        cnt = 0;
        for (j = i - 1; j >= 0; j--)
            if (Queue[i] > Queue[j])
                cnt++;
        code += fact[i] * cnt;
    }
    cout << code;
    return 0;
}