#include <bits/stdc++.h>
using namespace std;
stack<double> fig; //Ϊ�˷��㣬ֱ���ö�ջ�����������������
stack<char> chr;
int main()
{
    int i = 0;
    bool fig_judge = false;       //�����ж��ǲ���������ȡ��������
    char chr_temp, str[19], temp; //���ڴ��������������
    double Lch, Rch;              //�����������ʱ�洢
    chr_temp = cin.get();         //�ȶ���һ���ַ������ں����ж�
    while (chr_temp != '\n')      //��ȡ����
    {
        if (chr_temp == ' ')
        {
            chr_temp = cin.get();
            continue;
        }
        if ((chr_temp == '+' || chr_temp == '-' || chr_temp == '*' || chr_temp == '/')&&cin.peek()==' ') //����������ʹ���chr���������ָ��������
        {
            chr.push(chr_temp);
            fig_judge = false; //��ʼ���ж�����
            chr_temp = cin.get();
            continue;
        }
        i = 0;
        memset(str, '\0', sizeof(str));                           //��ʼ������
        str[i++] = chr_temp;                                      //�����е�����˵����ȡ�������֣��ȴ�������
        while ((chr_temp = cin.get()) != ' ' && chr_temp != '\n') //ֻҪû�ж�ȡ���ո�ʹ������飬����س�������
            str[i++] = chr_temp;
        Rch = atof(str);
        if (fig_judge) //��������������־Ϳ�ʼ����
        {
            Lch = fig.top(); //�õ���һ�ζ���������
            fig.pop();
            temp = chr.top(); //�õ����һ��ѹ��������
            chr.pop();
            switch (temp)
            {
            case '+':
                Lch += Rch;
                break;
            case '-':
                Lch -= Rch;
                break;
            case '*':
                Lch *= Rch;
                break;
            case '/':
                Lch /= Rch;
                break;
            }
            Rch = Lch; //���ں��潲������ѹ��ջ
        }
        fig.push(Rch);
        fig_judge = true;
        if (chr_temp == '\n')
            break;
        chr_temp = cin.get();
    }
    while (chr.size() != 0) //�������������ͼ�����������
    {
        Rch = fig.top();
        fig.pop();
        Lch = fig.top();
        fig.pop();
        temp = chr.top();
        chr.pop();
        switch (temp)
        {
        case '+':
            Lch += Rch;
            break;
        case '-':
            Lch -= Rch;
            break;
        case '*':
            Lch *= Rch;
            break;
        case '/':
            Lch /= Rch;
            break;
        }
        fig.push(Lch);
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << fig.top() << endl; //�̶����6λС��
    return 0;
}