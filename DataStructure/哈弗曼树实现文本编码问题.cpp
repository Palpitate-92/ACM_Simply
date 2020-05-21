#include <bits/stdc++.h>
using namespace std;
const int N = 26;               //����ַ���������Ĭ��ֻ�����д��ĸ
const int deff = 64;            //���ַ�ת��Ϊ�±��ʾʱ�Ĳ�ֵ�����ַ�Ƶ�������Ӧ
int frequen[N + 1];             //�ַ�Ƶ�����飬Ĭ�����±�1,2,3...����A,B,C...
char Character[N + 1];          //�洢���ֹ����ַ�
int Node_value[2 * N];          //�������нڵ��ֵ��Ĭ�ϴ�С��������
const int N_max = 67108864 - 1; /*���ܴ��ڵ�������,�˴���67108864��Ӧpow(2,N)��ֵ������ĳЩ�����������ƣ�û����N�����ַ��������ʱ,����������ʵ�־Ͳ�����������*/
int HFM_tree[N_max + 1];        //����������Ĭ����һά����ʵ�֣����ַ��������ʱ���Կ����ýṹ��ʵ��
int cnt_max = 1;                //��������������������ڵ�
priority_queue<int, vector<int>, greater<int>> pq;
int Coding[N + 1][N]; //��ά���鴢������ַ��ı���
int coding_temp[N];   //������ʱ������飬Ϊ����
int main()
{
    void cod_pro(int); //�������뺯��
    ifstream infile;   //���������ļ�������Ĭ��ֱ�Ӵ��ļ��ж�ȡ�ַ�����Ƶ�ʣ�Ĭ���ļ����ݸ�ʽΪ��A 1 B 2 C 3...(ÿ������֮��һ���ո�)
    infile.open("ch_frequen", ios::in);
    if (!infile) //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open ch_frequen error!\n";
        exit(1);
    }
    int frequen_temp, node = 0, i;
    char ch_temp;
    memset(Character, '\0', sizeof(Character));
    while (infile >> ch_temp) //��ȡ�����ַ�Ƶ�ʣ�������<<�����������ʵ�ֶ��룬���Բ����ж��Ƿ��ļ�β
    {
        infile >> frequen_temp;
        frequen[ch_temp - deff] = frequen_temp;
        Character[node] = ch_temp;
        pq.push(frequen_temp);
        node++;
    }
    infile.close(); //�ر������ļ�
    /*���ĵ�Ϊ��ͨ�ĵ�ʱ����ȷ��Ƶ�ʣ������
    void cod_pro(int); //�������뺯��
    ifstream infile;   //���������ļ�������
    infile.open("frequen_de", ios::in);
    if (!infile) //�����ʧ�ܣ�infile������ֵ
    {
        cerr << "open frequen_de error!\n";
        exit(1);
    }
    memset(Character, '\0', sizeof(Character));
    char ch_temp;
    int node = 0, i;                          //�������ַ�����
    while (ch_temp=infile.get())               //�����ı��ĵ������ڴ˴�д�����⣬while�жϵ���ch_temp�Ƿ���ֵ��������Ҫ�ֶ��ж��Ƿ񵽴��ļ�β
        if (ch_temp >= 'A' && ch_temp <= 'Z') //Ĭ��ֻ����A~Z
        {
            if (!frequen[ch_temp - deff]) //�жϵ�ǰ�ַ��Ƿ���ֹ�
                Character[node++] = ch_temp;
            frequen[ch_temp - deff]++;
        if (infile.peek() == EOF) //�ж��Ƿ�����ļ�β��������ѭ��
            break;
        }
    infile.close();
    for (i = 0; i < node; i++)
        pq.push(frequen[Character[i] - deff]);
        */
    node = 2 * node - 1; //�õ����������ڵ���
    int Lch, Rch, k = 0;
    while (true) //�����ַ�Ƶ�ʣ��õ����нڵ�ֵ
    {
        Lch = pq.top();
        Node_value[++k] = Lch;
        pq.pop();
        if (pq.size() == 0) //������ڵ�ֵ������ѭ��
            break;
        Rch = pq.top();
        Node_value[++k] = Rch;
        pq.pop();
        pq.push(Lch + Rch); //ѹ���丸�׽ڵ�ֵ
    }
    int cnt = 0;
    HFM_tree[++cnt] = Node_value[k--];
    while (cnt < node) //������������
    {
        Rch = Node_value[k--];         //�Ҷ��ӣ��ϴ�ֵ
        Lch = Node_value[k--];         //����ӣ��ϴ�ֵ
        for (i = 1; i <= cnt_max; i++) //Ѱ���丸�ף��Ե�һ��������Ϊ׼������������ʿ���Խ������
            if (HFM_tree[i] == Rch + Lch)
                break;
        HFM_tree[2 * i] = Lch;
        HFM_tree[2 * i + 1] = Rch;
        cnt_max = (cnt_max > 2 * i + 1) ? cnt_max : 2 * i + 1; //��֤��Ϊ���ֹ������ڵ�
        cnt += 2;
    }
    node = (node + 1) / 2;              //�ص���������ַ�����
    memset(Coding, -1, sizeof(Coding)); //�����ǳ�ʼ��Ϊ-1�����Կ���ֱ����memset����
    cod_pro(1);                         //���ñ��뺯��ʵ�ֱ���
    sort(Character, Character + node);  //Ĭ�����ַ�˳���������
    ofstream outfile;                   //��������ļ�������
    outfile.open("coding", ios::out);
    if (!outfile) //��֤���ļ��������������
    {
        cerr << "open coding error!\n";
        exit(1);
    }
    for (i = 0; i < node; i++) //���ַ�����������ļ�coding
    {
        outfile << Character[i] << " ";
        k = 0;
        while (Coding[Character[i] - deff][k] != -1)
        {
            outfile << Coding[Character[i] - deff][k];
            k++;
        }
        outfile << '\n'; //����±����ļ�ĩβΪ�س�
    }
    outfile.close();
    return 0;
}
void cod_pro(int cnt)
{
    bool Lch = true, Rch = true;                     //�жϸýڵ��Ƿ�ΪҶ�ӽڵ�
    if (cnt * 2 < cnt_max && HFM_tree[cnt * 2] != 0) //�����������Խ�磬���ж�������Ƿ����
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
        value = HFM_tree[cnt];   //�洢�ýڵ��ֵ
        for (i = 1; i <= N; i++) //Ѱ�Ҹýڵ��Ӧ���ַ�
            if (frequen[i] == value)
                break;
        dec = cnt;
        while (dec >= 2) //�ö����Ʒ�ʽ����ڵ㣬�õ�����
        {
            j = dec % 2;
            coding_temp[++k] = j;
            dec /= 2;
        }
        j = 0;
        while (k > -1) //�����ű���
            Coding[i][j++] = coding_temp[k--];
    }
}