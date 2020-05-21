#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    string Data;             //数据存储项，用于保存相应的数据
    vector<Node *> Children; //孩子节点指针存储，用于存储指向孩子节点的指针
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
        for (vector<Node *>::iterator it = root->Children.begin(); it != root->Children.end(); it++)//迭代器it
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