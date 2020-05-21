#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 4 * 1e7;
int small_top[N];
int main()
{
    int n = -1, i, k, p;
    clock_t start_time, end_time;
    start_time = clock();
    int temp;
    ifstream infile;
    infile.open("file_in", ios::in);//�ﵽ
    while (infile >> temp)
        small_top[++n] = temp;
    infile.close();
    end_time = clock();
    cout << end_time - start_time << endl;
    start_time = clock();
    for (i = 1; i <= n; i++)
    {
        k = i;
        while (k != 0)
            if (small_top[k] < small_top[k / 4])
            {
                swap(small_top[k], small_top[k / 4]);
                k /= 4;
            }
            else
                break;
    }
    for (i = n; i > 0; i--)
    {
        k = 0;
        swap(small_top[k], small_top[i]);
        while (k < i)
        {
            p = k;
            if (k * 4 < i && small_top[k] > small_top[k * 4])
                p = k * 4;
            if (k * 4 + 1 < i && small_top[p] > small_top[k * 4 + 1])
                p = k * 4 + 1;
            if (k * 4 + 2 < i && small_top[p] > small_top[k * 4 + 2])
                p = k * 4 + 2;
            if (k * 4 + 3 < i && small_top[p] > small_top[k * 4 + 3])
                p = k * 4 + 3;
            if (p == k)
                break;
            swap(small_top[p], small_top[k]);
            k = p;
        }
    }
    /*for (i = 1; i <= n; i++)
        printf("%d ", small_top[i]);*/
    end_time = clock();
    cout << end_time - start_time << endl;
    start_time = clock();
    ofstream outfile;
    outfile.open("file1", ios::out);
    i = -1;
    while (i < n)
        cout << small_top[++i] << " ";
    outfile.close();
    end_time = clock();
    cout << end_time - start_time;
    return 0;
}
