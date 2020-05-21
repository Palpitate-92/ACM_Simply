#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 4 * 1e7;
int small_top[N];
int main()
{
    int n = 0, i, k, p;
    //scanf("%d", &n);
    clock_t start_time, end_time;
    start_time = clock();
    int temp;
    /*for (i = 1; i <= n; i++)
        scanf("%d", &small_top[i]);*/
    ifstream infile;
    infile.open("file_in", ios::in);
    while (infile >> temp)
        small_top[++n] = temp;
    infile.close();
    end_time = clock();
    cout << end_time - start_time << endl;
    start_time = clock();
    for (i = 2; i <= n; i++) //建立小顶堆
    {
        k = i;
        while (k != 1)
            if (small_top[k] < small_top[k / 2])
            {
                swap(small_top[k], small_top[k / 2]);
                k /= 2;
            }
            else
                break;
    }
    for (i = n; i > 1; i--) //不断删顶
    {
        k = 1;
        swap(small_top[k], small_top[i]);
        while (k < i)
        {
            p = k;
            if (k * 2 < i && small_top[k] > small_top[k * 2])
                p = k * 2;
            if (k * 2 + 1 < i && small_top[p] > small_top[k * 2 + 1])
                p = k * 2 + 1;
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
    outfile.open("file2", ios::out);
    i = 0;
    while (i < n)
        outfile << small_top[++i] << " ";
    outfile.close();
    end_time = clock();
    cout << end_time - start_time;
    return 0;
}