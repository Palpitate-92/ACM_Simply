#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    string Data;             //���ݴ洢����ڱ�����Ӧ������
    vector<Node *> Children; //���ӽڵ�ָ��洢�����ڴ洢ָ���ӽڵ��ָ��
} Node;
void BuildTree(Node *root)
{
    string str;
    cin >> str;
    if (str == "END")
    {
        cout << "leave" << endl;
        Node *t = new Node;
        t->Data = "END";
        root->Children.push_back(t);
        return;
    }
    else
    {
        cout << "brand" << endl;
        Node *t = new Node;
        t->Data = str;
        root->Children.push_back(t);
        for (int i = 0; i < 3; i++)
            BuildTree(t);
    }
}
void Show(Node *root)
{
    if (root->Data == "END")
    {
        cout << "Leave node" << endl;
        return;
    }
    else
    {
        cout << root->Data << endl;
        for (vector<Node *>::iterator it = root->Children.begin(); it != root->Children.end(); it++)//������it
        {
            Node *temp = *it;
            Show(temp);
        }
    }
}
int main()
{
    Node *root;
    root = new Node;
    BuildTree(root);
    Show(root);
    return 0;
}