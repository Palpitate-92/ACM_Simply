#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int ans[2 * N];
int main()
{
    int i, k, n, y;
    freopen("1.in", "r", stdin);//输入重定向，把标准输入设备重定向到输入文件“1.in”
    freopen("1.out","w",stdout);//输出重定向，把标准输出设备重定向到输出文件“1.in”
    while(scanf("%d",&k)==1)
    {
        n = 0;
        for (y = k + 1; y <= 2 * k;y++)
        if((k*y)%(y-k)==0)
            ans[n++] = y;
        printf("%d\n", n);
        for (i = 0; i < n;i++)
        {
            y = ans[i];
            printf("1/%d = 1/%d + 1/%d\n", k, (k * y) / (y - k), y);
        }
    }
    return 0;
}