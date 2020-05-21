#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int main()
{
    int i;
    ofstream outfile;
    outfile.open("f1", ios::out);
    srand((unsigned)time(NULL));
    for (i = 0; i < N; i++)
        outfile << rand() % 100000 << " ";
    for (i = 0; i < 990; i++)
        outfile << 130000 << " ";
    cout << i;
    outfile.close();
    return 0;
}