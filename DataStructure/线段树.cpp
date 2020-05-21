#include <bits/stdc++.h>
using namespace std;
#define maxn 100007 //Ԫ���ܸ���
#define ls l, m, rt << 1
#define rs m + 1, r, rt << 1 | 1
int Sum[maxn << 2], Add[maxn << 2]; //Sum��ͣ�AddΪ������
int A[maxn], n;                     //��ԭ���������±�[1,n]
//PushUp�������½ڵ���Ϣ �����������
void PushUp(int rt) { Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1]; }
//Build��������
void Build(int l, int r, int rt)
{ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
    if (l == r)
    {                   //������Ҷ�ڵ�
        Sum[rt] = A[l]; //��������ֵ
        return;
    }
    int m = (l + r) >> 1;
    //���ҵݹ�
    Build(l, m, rt << 1);
    Build(m + 1, r, rt << 1 | 1);
    //������Ϣ
    PushUp(rt);
}
void PushDown(int rt, int ln, int rn)
{
    //ln,rnΪ��������������������������
    if (Add[rt])
    {
        //���Ʊ��
        Add[rt << 1] += Add[rt];
        Add[rt << 1 | 1] += Add[rt];
        //�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ
        Sum[rt << 1] += Add[rt] * ln;
        Sum[rt << 1 | 1] += Add[rt] * rn;
        //������ڵ���
        Add[rt] = 0;
    }
}
void Update(int L, int C, int l, int r, int rt)
{ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
    if (l == r)
    { //��Ҷ�ڵ㣬�޸�
        Sum[rt] += C;
        return;
    }
    int m = (l + r) >> 1;
    //���������ж������������û�������
    if (L <= m)
        Update(L, C, l, m, rt << 1);
    else
        Update(L, C, m + 1, r, rt << 1 | 1);
    PushUp(rt); //�ӽڵ�����ˣ����Ա��ڵ�Ҳ��Ҫ������Ϣ
}
void Update(int L, int R, int C, int l, int r, int rt)
{ //L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
    if (L <= l && r <= R)
    {                               //�����������ȫ�ڲ�������[L,R]����
        Sum[rt] += C * (r - l + 1); //�������ֺͣ����ϱ�����ȷ
        Add[rt] += C;               //����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������
        return;
    }
    int m = (l + r) >> 1;
    PushDown(rt, m - l + 1, r - m); //���Ʊ��
    //�����ж�����������[L,R]���޽������н����ŵݹ�
    if (L <= m)
        Update(L, R, C, l, m, rt << 1);
    if (R > m)
        Update(L, R, C, m + 1, r, rt << 1 | 1);
    PushUp(rt); //���±��ڵ���Ϣ
}
int Query(int L, int R, int l, int r, int rt)
{ //L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
    if (L <= l && r <= R)
    {
        //�������ڣ�ֱ�ӷ���
        return Sum[rt];
    }
    int m = (l + r) >> 1;
    //���Ʊ�ǣ�����Sum���ܲ���ȷ
    PushDown(rt, m - l + 1, r - m);
    //�ۼƴ�
    int ANS = 0;
    if (L <= m)
        ANS += Query(L, R, l, m, rt << 1);
    if (R > m)
        ANS += Query(L, R, m + 1, r, rt << 1 | 1);
    return ANS;
}
