#include <bits/stdc++.h>
using namespace std;
const int N = 26;       //最大字符种类数，默认只处理大写字母,跟随字符编码程序中的N
const int deff = 64;    //将字符转换为下标表示时的差值，跟随字符编码程序中的deff
const int deff_co = 48; //char型数字转换为int型数字的差值
int Coding[N + 1][N];   //二维数组储存各个字符的编码
int main()
{
    ifstream infile; //建立输入文件流对象
    infile.open("coding", ios::in);
    if (!infile) //如果打开失败，infile返回零值
    {
        cerr << "open coding error!\n";
        exit(1);
    }
    char ch_temp, coding_temp, i = 0;
    memset(Coding, -1, sizeof(Coding)); //由于是初始化为-1，所以可以直接用memset函数
    while (infile.get(ch_temp))      //读取编码
    {
        //infile.ignore(117, ' '); //由于编码文档的格式问题，跳过字母与编码之间的空格，数字一般情况下取为1即可
        i = 0;
        while (true)
        {
            infile >> coding_temp;
            Coding[ch_temp - deff][i++] = coding_temp - deff_co; //用插入类型处理编码，保证一位一位读入字符编码
            if (infile.peek() == '\n')                           //避免在编码数组中存入字母
                break;
        }
        infile.ignore(117, '\n'); //由于编码文档的格式问题，还要跳过行与行之间的空格，数字一般情况下取为1即可
        /*if (infile.peek() == EOF) //由于此时while判断的是infile.get(ch_temp)，所以不用判断是否达到文件尾
            break;*/
    }
    infile.close();  //关闭输入文件
    infile.open("document_be", ios::in);//与document_be文件建立关联
    if (!infile) //如果打开失败，infile返回零值
    {
        cerr << "open document_be error!\n";
        exit(1);
    }
    ofstream outfile; //建立输出文件流对象
    outfile.open("document_co", ios::out);
    if (!outfile) //如果打开失败，outfile返回零值
    {
        cerr << "open document_co error!\n";
        exit(1);
    }
    while (ch_temp = infile.get())//将document_be文件编码重输出
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