#include <bits/stdc++.h>
using namespace std;
const int N = 26;               //最大字符种类数，默认只处理大写字母
const int deff = 64;            //将字符转换为下标表示时的差值，与字符频率数组对应
int frequen[N + 1];             //字符频率数组，默认以下标1,2,3...代表A,B,C...
char Character[N + 1];          //存储出现过的字符
int Node_value[2 * N];          //保存所有节点的值，默认从小到大排序
const int N_max = 67108864 - 1; /*可能存在的最差情况,此处的67108864对应pow(2,N)的值，由于某些编译器的限制，没有用N，当字符种类过大时,哈夫曼树的实现就不该用数组了*/
int HFM_tree[N_max + 1];        //哈弗曼树，默认以一维数组实现，当字符种类过多时可以考虑用结构体实现
int cnt_max = 1;                //哈夫曼树中有意义的最大节点
priority_queue<int, vector<int>, greater<int>> pq;
int Coding[N + 1][N]; //二维数组储存各个字符的编码
int coding_temp[N];   //编码临时存放数组，为逆序
int main()
{
    void cod_pro(int); //声明编码函数
    ifstream infile;   //建立输入文件流对象，默认直接从文件中读取字符与其频率，默认文件数据格式为：A 1 B 2 C 3...(每个数据之间一个空格)
    infile.open("ch_frequen", ios::in);
    if (!infile) //如果打开失败，infile返回零值
    {
        cerr << "open ch_frequen error!\n";
        exit(1);
    }
    int frequen_temp, node = 0, i;
    char ch_temp;
    memset(Character, '\0', sizeof(Character));
    while (infile >> ch_temp) //读取各个字符频率，由于是<<流插入运算符实现读入，所以不用判断是否到文件尾
    {
        infile >> frequen_temp;
        frequen[ch_temp - deff] = frequen_temp;
        Character[node] = ch_temp;
        pq.push(frequen_temp);
        node++;
    }
    infile.close(); //关闭输入文件
    /*当文档为普通文档时，先确定频率，后编码
    void cod_pro(int); //声明编码函数
    ifstream infile;   //建立输入文件流对象
    infile.open("frequen_de", ios::in);
    if (!infile) //如果打开失败，infile返回零值
    {
        cerr << "open frequen_de error!\n";
        exit(1);
    }
    memset(Character, '\0', sizeof(Character));
    char ch_temp;
    int node = 0, i;                          //待编码字符个数
    while (ch_temp=infile.get())               //处理文本文档，由于此处写法问题，while判断的是ch_temp是否有值，所以需要手动判断是否到达文件尾
        if (ch_temp >= 'A' && ch_temp <= 'Z') //默认只处理A~Z
        {
            if (!frequen[ch_temp - deff]) //判断当前字符是否出现过
                Character[node++] = ch_temp;
            frequen[ch_temp - deff]++;
        if (infile.peek() == EOF) //判断是否读到文件尾，避免死循环
            break;
        }
    infile.close();
    for (i = 0; i < node; i++)
        pq.push(frequen[Character[i] - deff]);
        */
    node = 2 * node - 1; //得到哈弗曼树节点数
    int Lch, Rch, k = 0;
    while (true) //处理字符频率，得到所有节点值
    {
        Lch = pq.top();
        Node_value[++k] = Lch;
        pq.pop();
        if (pq.size() == 0) //存入根节点值后跳出循环
            break;
        Rch = pq.top();
        Node_value[++k] = Rch;
        pq.pop();
        pq.push(Lch + Rch); //压入其父亲节点值
    }
    int cnt = 0;
    HFM_tree[++cnt] = Node_value[k--];
    while (cnt < node) //建立哈夫曼树
    {
        Rch = Node_value[k--];         //右儿子，较大值
        Lch = Node_value[k--];         //左儿子，较大值
        for (i = 1; i <= cnt_max; i++) //寻找其父亲，以第一个遇到的为准，避免数组访问可能越界的情况
            if (HFM_tree[i] == Rch + Lch)
                break;
        HFM_tree[2 * i] = Lch;
        HFM_tree[2 * i + 1] = Rch;
        cnt_max = (cnt_max > 2 * i + 1) ? cnt_max : 2 * i + 1; //保证其为出现过的最大节点
        cnt += 2;
    }
    node = (node + 1) / 2;              //回到待编码的字符个数
    memset(Coding, -1, sizeof(Coding)); //由于是初始化为-1，所以可以直接用memset函数
    cod_pro(1);                         //调用编码函数实现编码
    sort(Character, Character + node);  //默认以字符顺序输出编码
    ofstream outfile;                   //建立输出文件流对象
    outfile.open("coding", ios::out);
    if (!outfile) //保证打开文件，避免特殊情况
    {
        cerr << "open coding error!\n";
        exit(1);
    }
    for (i = 0; i < node; i++) //将字符编码输出至文件coding
    {
        outfile << Character[i] << " ";
        k = 0;
        while (Coding[Character[i] - deff][k] != -1)
        {
            outfile << Coding[Character[i] - deff][k];
            k++;
        }
        outfile << '\n'; //该项导致编码文件末尾为回车
    }
    outfile.close();
    return 0;
}
void cod_pro(int cnt)
{
    bool Lch = true, Rch = true;                     //判断该节点是否为叶子节点
    if (cnt * 2 < cnt_max && HFM_tree[cnt * 2] != 0) //避免数组访问越界，再判断左儿子是否存在
    {
        cod_pro(cnt * 2);
        Lch = false;
    }
    if (cnt * 2 + 1 <= cnt_max && HFM_tree[cnt * 2 + 1] != 0)
    {
        cod_pro(cnt * 2 + 1);
        Rch = false;
    }
    if (Lch && Rch)
    {
        int value, dec, i, j, k = -1;
        value = HFM_tree[cnt];   //存储该节点的值
        for (i = 1; i <= N; i++) //寻找该节点对应的字符
            if (frequen[i] == value)
                break;
        dec = cnt;
        while (dec >= 2) //用二进制方式处理节点，得到编码
        {
            j = dec % 2;
            coding_temp[++k] = j;
            dec /= 2;
        }
        j = 0;
        while (k > -1) //正序存放编码
            Coding[i][j++] = coding_temp[k--];
    }
}