#include <bits/stdc++.h>
using namespace std;
const int N = 26;               //����ַ���������Ĭ��ֻ�����д��ĸ,�����ַ���������е�N
const int deff = 64;            //���ַ�ת��Ϊ�±��ʾʱ�Ĳ�ֵ�������ַ���������е�deff
const int N_max = 67108864 - 1; //���ܴ��ڵ�������,�����ַ���������N_max
int hfm_tree[N_max + 1];        //���ݱ��룬�������ƹ������������ݽṹ
const int deff_co = 48;         //char������ת��Ϊint�����ֵĲ�ֵ�������ĵ���������е�deff_co
int Coding[N + 1][N];           //��ά���鴢������ַ��ı��룬�����ĵ���������е�Coding
int main()
{                    //���Ȼ���ַ��ı��룬���ĵ������еķ�ʽһ��
    ifstream infile; //���������ļ�������
    infile.open("coding", ios::in);
    if (!infile) //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open coding error!\n";
        exit(1);
    }
    char ch_temp, coding_temp, i = 0;
    memset(Coding, -1, sizeof(Coding)); //�����ǳ�ʼ��Ϊ-1�����Կ���ֱ����memset����
    while (infile.get(ch_temp))         //��ȡ����
    {
        infile.ignore(117, ' '); //���ڱ����ĵ��ĸ�ʽ���⣬������ĸ�����֮��Ŀո�����һ�������ȡΪ1����
        i = 0;
        while (true)
        {
            infile >> coding_temp;
            Coding[ch_temp - deff][i++] = coding_temp - deff_co; //�ò������ʹ�����룬��֤һλһλ�����ַ�����
            if (infile.peek() == '\n')                           //�����ڱ��������д�����ĸ
                break;
        }
        infile.ignore(117, '\n'); //���ڱ����ĵ��ĸ�ʽ���⣬��Ҫ����������֮��Ŀո�����һ�������ȡΪ1����
    }
    infile.close(); //�ر������ļ�
    int j, cnt = 1;
    for (i = 1; i <= N; i++) //����������ĸ�ı��룬�����Ƿ��б��룬������hfm_tree
    {
        j = 0;
        cnt = 1;
        while (Coding[i][j] != -1) //Ѱ��i������ĵ��ַ�Ӧ���Ľڵ���,����·���о��������нڵ��ʼ��Ϊ-1�����ڲ���
        {
            cnt = cnt * 2 + Coding[i][j++];
            hfm_tree[cnt] = -1;
        }
        if (cnt > N_max) //���������������������ַ������ļ����ַ����������������������������ļ��𻵣����޸Ĺ�
        {
            cerr << "Program error!Please check the input file!\n";
            exit(1);
        }
        hfm_tree[cnt] = i;
    }
    infile.open("document_co", ios::in); //��document_co�ļ���������
    if (!infile)                         //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open document_co error!\n";
        exit(1);
    }
    ofstream outfile; //����������ļ�����
    outfile.open("document_af", ios::out);
    if (!outfile) //�����ʧ�ܣ�outfile������ֵ
    {
        cerr << "open document_af error!\n";
        exit(1);
    }
    cnt = 1;
    while (infile.get(ch_temp)) //�Ա������ļ����벢���
    {
        if (ch_temp == ' ') //����ǿո��ֱ�����
        {
            outfile << ' ';
            cnt = 1; //��ʼ���ڵ�
            continue;
        }
        cnt = cnt * 2 + ch_temp - deff_co;
        if (2 * cnt >= N_max || hfm_tree[2 * cnt] == 0) //�жϸýڵ������Ӳ����ڣ����ڸýṹ���������⣬ֻ��Ҫ�ж�����Ӽ���
        {
            outfile << char(hfm_tree[cnt] + deff);
            cnt = 1; //��ʼ���ڵ�
        }
    }
    infile.close();
    outfile.close();
    return 0;
}