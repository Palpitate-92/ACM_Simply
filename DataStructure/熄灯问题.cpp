#include <bits/stdc++.h>
using namespace std;
int puzzle[6][8], press[6][8];
bool guess()
{
    int c, r;
    for (r = 1; r < 5; r++)
        for (c = 1; c < 7; c++)
            press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
    for (c = 1; c < 7; c++)
        if ((puzzle[5][c] + press[5][c] + press[4][c] + press[5][c - 1] + press[5][c + 1]) % 2)
            return false;
    return true;
}
void enumate()
{
    int c;
    while (!guess())
    {
        press[1][6]++;
        c = 6;
        while (press[1][c] > 1)
        {
            press[1][c] = 0;
            press[1][--c]++;
        }
    }
}
int main()
{
    int cases, i = 1, r, c;
    cin >> cases;
    while (i <= cases)
    {
        for (r = 1; r < 6; r++)
            for (c = 1; c < 7; c++)
                cin >> puzzle[r][c];
        enumate();
        printf("PUZZLE #%d\n", i);
        for (r = 1; r < 6; r++)
        {
            for (c = 1; c < 7; c++)
                cout << press[r][c] << ' ';
            cout << '\n';
        }
        i++;
    }
    return 0;
}