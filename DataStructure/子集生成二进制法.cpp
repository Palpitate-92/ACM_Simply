#include <bits/stdc++.h>
using namespace std;
int a[10], n;
void creat_subset(int cur)
{
    for (int i = 0; i < n; i++)
    {
        if (cur & (1 << i))//a&b 返回a与b的二进制格式中每一位两个值中最小的值，最后合并成一个数  1100&0011 返回0000
            printf("%d ", a[i]);
    }
    puts("");
}
int main()
{
    while ((scanf("%d", &n)) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < (1 << n); i++)//二进制操作
            creat_subset(i);
    }
    return 0;
}