#include <bits/stdc++.h>
using namespace std;
const int N_max = 1000;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    ifstream infile; //���������ļ�������
    infile.open("f1", ios::in);
    if (!infile) //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open f1 error!\n";
        exit(1);
    }
    int count = 0, temp;
    while (infile >> temp) //�ȶ���1000������������
    {
        pq.push(temp);
        count++;
        if (count == N_max)
            break;
    }
    while (infile >> temp) //��ʼ����֮������ݲ��ұȽ�
    {
        if (temp > pq.top())
        {
            pq.pop();
            pq.push(temp);
        }
        if (pq.size() > N_max)//�������ۣ������������
        {
            cerr << "Data processing failed!\n";
            infile.close();
            exit(1);
        }
    }
    infile.close();   //�ر������ļ�fl
    ofstream outfile; //��������ļ�������
    outfile.open("f2", ios::out);
    if (!outfile) //��֤���ļ��������������
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