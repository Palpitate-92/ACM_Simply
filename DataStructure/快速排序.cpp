#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 4 * 1e7;
int Num[N];
void quick_sort(int L, int R)
{
    if (L >= R)
        return;
    int i, j, temp;
    i = L;
    j = R;
    //swap(Num[i], Num[rand() % (R - L + 1) + L]);
    temp = Num[i];
    while (i < j)
    {
        while (i < j && Num[j] >= temp)
            j--;
        if (i < j)
            Num[i++] = Num[j];
        while (i < j && Num[i] <= temp)
            i++;
        if (i < j)
            Num[j--] = Num[i];
    }
    Num[i] = temp;
    quick_sort(L, i - 1);
    quick_sort(i + 1, R);
}
int main()
{
    clock_t start_time, end_time;
    start_time = clock();
    int i = 0, temp, j = 1;
    ifstream infile;
    infile.open("file_in", ios::in);
    while (infile >> temp)
        Num[++i] = temp;
    infile.close();
    end_time = clock();
    cout << end_time - start_time << endl;
    srand((unsigned)time(NULL));
    start_time = clock();
    quick_sort(1, i);
    end_time = clock();
    cout << end_time - start_time << endl;
    start_time = clock();
    ofstream outfile;
    outfile.open("file_out", ios::out);
    while (j <= i)
        cout << Num[j++] << " ";
    outfile.close();
    end_time = clock();
    cout << end_time - start_time;
    return 0;
}