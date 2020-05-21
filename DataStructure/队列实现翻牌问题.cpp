/*
template<
    class T,
    class Container = std::deque<T>
> class queue;
queue<int>q
q.front()  q.back()
q.empty()  q.size()
q.push()   q.pop()
q.swap()
*/
#include <bits/stdc++.h>
using namespace std;
queue<int> q;//size() ���ض�����Ԫ�ظ���  back()  ���ض�βԪ��
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        q.push(i);
    while (!q.empty())
    {
        printf("%d ", q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}