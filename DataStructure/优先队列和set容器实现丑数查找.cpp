/*丑数是指不能被2，3，5之外的素数整除的正整数。本代码将丑数从小到大排序并输出第1500个丑数*/
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