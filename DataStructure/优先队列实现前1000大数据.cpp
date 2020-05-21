#include <bits/stdc++.h>
using namespace std;
const int N_max = 1000;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    ifstream infile; //建立输入文件流对象
    infile.open("f1", ios::in);
    if (!infile) //如果打开失败，infile返回零值
    {
        cerr << "open f1 error!\n";
        exit(1);
    }
    int count = 0, temp;
    while (infile >> temp) //先读入1000个数据用作基
    {
        pq.push(temp);
        count++;
        if (count == N_max)
            break;
    }
    while (infile >> temp) //开始读入之后的数据并且比较
    {
        if (temp > pq.top())
        {
            pq.pop();
            pq.push(temp);
        }
        if (pq.size() > N_max)//留个心眼，避免意外情况
        {
            cerr << "Data processing failed!\n";
            infile.close();
            exit(1);
        }
    }
    infile.close();   //关闭输入文件fl
    ofstream outfile; //建立输出文件流对象
    outfile.open("f2", ios::out);
    if (!outfile) //保证打开文件，避免特殊情况
    {
        cerr << "open f2 error!\n";
        exit(1);
    }
    while (count > 0)
    {
        outfile << pq.top() << " ";
        pq.pop();
        count--;
    }
    outfile.close();
    return 0;
}