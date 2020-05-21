/*
���ȶ��У�priority_queue)����������ʽ
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
*/
#include <bits/stdc++.h>
using namespace std;
/*struct opp
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        /*
        if (lhs % 10 == rhs % 10 && lhs > rhs)//���ؼٷ�������(top)���������������
            return true;
        else if (lhs % 10 > rhs % 10)
            return true;
        else
            return false;

        return lhs % 10 < rhs % 10;
    }
};*/
//priority_queue<int, vector<int>, opp> pq; //priority_queue<int, vector<int>, less(greater)<int> (�˴���һ���ո��������)> pq;
priority_queue<int> pq;
int main()
{
    clock_t start_time, end_time;
    start_time = clock();
    int temp;
    /*for (int i = 0; i < 10; i++)
    {
        temp = rand() % 100; //�������0~99������
        pq.push(temp);
        printf("%d ", temp);
    }*/
    ifstream infile;
    infile.open("file", ios::in);
    while (infile >> temp)
        pq.push(temp);
    //printf("\n");
    infile.close();
    ofstream outfile;
    outfile.open("file_out", ios::out);
    while (!pq.empty())
    {
        outfile << pq.top() << " ";
        pq.pop();
    }
    outfile.close();
    end_time = clock();
    cout << end_time - start_time;
    return 0;
}