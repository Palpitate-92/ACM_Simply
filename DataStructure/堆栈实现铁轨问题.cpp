/*
template<
    class T,
    class Container = std::deque<T>
> class stack;
stack<int>s
s.top()   s.pop()
s.push()  s.empty()
s.size()  s.swap()
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int Expect[N];
stack<int> s;//size()  返回堆栈中元素个数
int main()
{
    int i, n, point_ex = 1, point_de = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &Expect[i]);
    while (point_ex <= n)
    {
        if (++point_de == Expect[point_ex])
            point_ex++;
        else if (!s.empty() && s.top() == Expect[point_ex])
        {
            point_ex++;
            point_de--;
            s.pop();
        }
        else if (Expect[point_ex] < point_de || point_de >= n)
            break;
        else
            s.push(point_de);
    }
    if (point_ex > n)
        printf("%s\n", "Yes");
    else
        printf("%s\n", "No");
    return 0;
}