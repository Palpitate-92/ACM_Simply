#include <bits/stdc++.h>
using namespace std;
const int N = 26;       //����ַ���������Ĭ��ֻ�����д��ĸ,�����ַ���������е�N
const int deff = 64;    //���ַ�ת��Ϊ�±��ʾʱ�Ĳ�ֵ�������ַ���������е�deff
const int deff_co = 48; //char������ת��Ϊint�����ֵĲ�ֵ
int Coding[N + 1][N];   //��ά���鴢������ַ��ı���
int main()
{
    ifstream infile; //���������ļ�������
    infile.open("coding", ios::in);
    if (!infile) //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open coding error!\n";
        exit(1);
    }
    char ch_temp, coding_temp, i = 0;
    memset(Coding, -1, sizeof(Coding)); //�����ǳ�ʼ��Ϊ-1�����Կ���ֱ����memset����
    while (infile.get(ch_temp))      //��ȡ����
    {
        //infile.ignore(117, ' '); //���ڱ����ĵ��ĸ�ʽ���⣬������ĸ�����֮��Ŀո�����һ�������ȡΪ1����
        i = 0;
        while (true)
        {
            infile >> coding_temp;
            Coding[ch_temp - deff][i++] = coding_temp - deff_co; //�ò������ʹ�����룬��֤һλһλ�����ַ�����
            if (infile.peek() == '\n')                           //�����ڱ��������д�����ĸ
                break;
        }
        infile.ignore(117, '\n'); //���ڱ����ĵ��ĸ�ʽ���⣬��Ҫ����������֮��Ŀո�����һ�������ȡΪ1����
        /*if (infile.peek() == EOF) //���ڴ�ʱwhile�жϵ���infile.get(ch_temp)�����Բ����ж��Ƿ�ﵽ�ļ�β
            break;*/
    }
    infile.close();  //�ر������ļ�
    infile.open("document_be", ios::in);//��document_be�ļ���������
    if (!infile) //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open document_be error!\n";
        exit(1);
    }
    ofstream outfile; //��������ļ�������
    outfile.open("document_co", ios::out);
    if (!outfile) //�����ʧ�ܣ�outfile������ֵ
    {
        cerr << "open document_co error!\n";
        exit(1);
    }
    while (ch_temp = infile.get())//��document_be�ļ����������
    {
        if (ch_temp == ' ')
        {
            outfile << ch_temp;
            continue;
        }
        i = 0;
        while (Coding[ch_temp - deff][i] != -1)
            outfile << Coding[ch_temp - deff][i++];
        if (infile.peek() == EOF)
            break;
    }
    infile.close();
    outfile.close();
    return 0;
}