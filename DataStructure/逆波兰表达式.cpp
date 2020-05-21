#include <bits/stdc++.h>
using namespace std;
stack<double> fig; //为了方便，直接用堆栈来处理运算符和数字
stack<char> chr;
int main()
{
    int i = 0;
    bool fig_judge = false;       //用来判断是不是连续读取到了数字
    char chr_temp, str[19], temp; //用于储存运算符和数字
    double Lch, Rch;              //用于运算和临时存储
    chr_temp = cin.get();         //先读入一个字符，便于后续判断
    while (chr_temp != '\n')      //读取数据
    {
        if (chr_temp == ' ')
        {
            chr_temp = cin.get();
            continue;
        }
        if ((chr_temp == '+' || chr_temp == '-' || chr_temp == '*' || chr_temp == '/')&&cin.peek()==' ') //读到运算符就存入chr，并且区分负号与减号
        {
            chr.push(chr_temp);
            fig_judge = false; //初始化判断条件
            chr_temp = cin.get();
            continue;
        }
        i = 0;
        memset(str, '\0', sizeof(str));                           //初始化数组
        str[i++] = chr_temp;                                      //能运行到这里说明读取到了数字，先存入数组
        while ((chr_temp = cin.get()) != ' ' && chr_temp != '\n') //只要没有读取到空格就存入数组，读入回车符跳出
            str[i++] = chr_temp;
        Rch = atof(str);
        if (fig_judge) //如果连续读到数字就开始计算
        {
            Lch = fig.top(); //得到上一次读到的数字
            fig.pop();
            temp = chr.top(); //得到最后一次压入的运算符
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
            Rch = Lch; //便于后面讲运算结果压入栈
        }
        fig.push(Rch);
        fig_judge = true;
        if (chr_temp == '\n')
            break;
        chr_temp = cin.get();
    }
    while (chr.size() != 0) //如果还有运算符就继续处理数据
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
    cout << setiosflags(ios::fixed) << setprecision(6) << fig.top() << endl; //固定输出6位小数
    return 0;
}