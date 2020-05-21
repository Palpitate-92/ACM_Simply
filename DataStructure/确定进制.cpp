#include <bits/stdc++.h>
using namespace std;
const int Base_max = 16; //最大基数设为16进制
int getBase(string s)
{
    int digit = s.size(); //返回s中的char T元素个数，相当于length
    char max = '0';
    for (int i = 0; i < digit; i++)
        if (s[i] > max)
            max = s[i];
    return max - '0' + 1;
}
int getNumber(string s, int Base)
{
    int digit = s.size();
    int sum = 0;
    for (int i = 0; i < digit; i++)
        sum = sum * Base + s[i] - '0';
    return sum;
}
int main()
{
    string p, q, r;
    cin >> p >> q >> r;
    int Base = getBase(p);
    if (getBase(q) > Base)
        Base = getBase(q);
    if (getBase(r) > Base)
        Base = getBase(r);
    for (; Base <= Base_max; Base++)
    {
        int p_value = getNumber(p, Base);
        int q_value = getNumber(q, Base);
        int r_value = getNumber(r, Base);
        if (p_value * q_value == r_value)
            break;
    }
    if (Base <= Base_max)
        cout << Base << endl;
    else
        cout << 0 << endl;
    return 0;
}