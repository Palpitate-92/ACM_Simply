/*������ָ���ܱ�2��3��5֮��������������������������뽫������С�������������1500������*/
/*
std::set Defined in header<set>
bool empty() const;
size_type size() const;
void clear();
insert(const value_type& value);
size_type erase(const key_type& key);
size_type count(count Key&key)const;
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int coeff[3] = {2, 3, 5};
priority_queue<LL, vector<LL>, greater<LL>> pq;
set<LL> s;
int main()
{
    LL x;
    pq.push(1);
    s.insert(1);
    for (int i = 2; i <= 1500; i++)
    {
        x = pq.top();
        pq.pop();
        for (int j = 0; j < 3; j++)
            if (s.count(x * coeff[j]) == 0)
            {
                pq.push(x * coeff[j]);
                s.insert(x * coeff[j]);
            }
    }
    printf("%d", pq.top());
    return 0;
}