#include <bits/stdc++.h>
using namespace std;
const int N = 26;               //最大字符种类数，默认只处理大写字母,跟随字符编码程序中的N
const int deff = 64;            //将字符转换为下标表示时的差值，跟随字符编码程序中的deff
const int N_max = 67108864 - 1; //可能存在的最差情况,跟随字符编码程序的N_max
int hfm_tree[N_max + 1];        //依据编码，建立类似哈弗曼树的数据结构
const int deff_co = 48;         //char型数字转换为int型数字的差值，跟随文档编码程序中的deff_co
int Coding[N + 1][N];           //二维数组储存各个字符的编码，跟随文档编码程序中的Coding
int main()
{                    //首先获得字符的编码，和文档编码中的方式一样
    ifstream infile; //建立输入文件流对象
    infile.open("coding", ios::in);
    if (!infile) //如果打开失败，infile返回零值
    {
        cerr << "open coding error!\n";
        exit(1);
    }
    char ch_temp, coding_temp, i = 0;
    memset(Coding, -1, sizeof(Coding)); //由于是初始化为-1，所以可以直接用memset函数
    while (infile.get(ch_temp))         //读取编码
    {
        infile.ignore(117, ' '); //由于编码文档的格式问题，跳过字母与编码之间的空格，数字一般情况下取为1即可
        i = 0;
        while (true)
        {
            infile >> coding_temp;
            Coding[ch_temp - deff][i++] = coding_temp - deff_co; //用插入类型处理编码，保证一位一位读入字符编码
            if (infile.peek() == '\n')                           //避免在编码数组中存入字母
                break;
        }
        infile.ignore(117, '\n'); //由于编码文档的格式问题，还要跳过行与行之间的空格，数字一般情况下取为1即可
    }
    infile.close(); //关闭输入文件
    int j, cnt = 1;
    for (i = 1; i <= N; i++) //遍历所有字母的编码，不管是否有编码，并建立hfm_tree
    {
        j = 0;
        cnt = 1;
        while (Coding[i][j] != -1) //寻找i所代表的的字符应处的节点数,并将路程中经过的所有节点初始化为-1，便于查找
        {
            cnt = cnt * 2 + Coding[i][j++];
            hfm_tree[cnt] = -1;
        }
        if (cnt > N_max) //如果出现这种情况，表明字符编码文件的字符编码错误，如果错误出现在这里，表明文件损坏，或被修改过
        {
            cerr << "Program error!Please check the input file!\n";
            exit(1);
        }
        hfm_tree[cnt] = i;
    }
    infile.open("document_co", ios::in); //与document_co文件建立关联
    if (!infile)                         //如果打开失败，infile返回零值
    {
        cerr << "open document_co error!\n";
        exit(1);
    }
    ofstream outfile; //建立输出流文件对象
    outfile.open("document_af", ios::out);
    if (!outfile) //如果打开失败，outfile返回零值
    {
        cerr << "open document_af error!\n";
        exit(1);
    }
    cnt = 1;
    while (infile.get(ch_temp)) //对编码后的文件解码并输出
    {
        if (ch_temp == ' ') //如果是空格就直接输出
        {
            outfile << ' ';
            cnt = 1; //初始化节点
            continue;
        }
        cnt = cnt * 2 + ch_temp - deff_co;
        if (2 * cnt >= N_max || hfm_tree[2 * cnt] == 0) //判断该节点的左儿子不存在，由于该结构的特性问题，只需要判断左儿子即可
        {
            outfile << char(hfm_tree[cnt] + deff);
            cnt = 1; //初始化节点
        }
    }
    infile.close();
    outfile.close();
    return 0;
}