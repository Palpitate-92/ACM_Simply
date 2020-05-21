#include <bits/stdc++.h>
using namespace std;
const int N = 1e3; //防止运行时时可能出现的数组被判定为越界
stack<int> Figure;
stack<int> Expr;
char ch[] = "+-*/()#";
int f1[] = {3, 3, 5, 5, 1, 6, 0};
int f2[] = {2, 2, 4, 4, 6, 1, 0};
int main()
{
    char temp;
    int lch, rch, sum, t1, t2;
    Expr.push(6);
    while (cin >> temp && temp != '#')
    {
        if (isdigit(temp))
        {
            sum = 0;
            while (isdigit(temp))
            {
                sum = sum * 10 + temp - '0';
                cin >> temp;
            }
            Figure.push(sum);
            if (temp == '#')
                break;
        }
        for (t2 = 0; t2 < 6; t2++)
            if (ch[t2] == temp)
                break;
        t1 = Expr.top();
        while (f1[t1] > f2[t2])
        {
            Expr.pop();
            rch = Figure.top();
            Figure.pop();
            lch = Figure.top();
            Figure.pop();
            switch (ch[t1])
            {
            case '+':
                lch += rch;
                break;
            case '-':
                lch -= rch;
                break;
            case '*':
                lch *= rch;
                break;
            case '/':
                lch /= rch;
                break;
            }
            Figure.push(lch);
            t1 = Expr.top();
        }
        if (f1[t1] < f2[t2])
            Expr.push(t2);
        else if (f1[t1] == f2[t2])
            Expr.pop();
    }
    if ((t1 = Expr.top()) != 6)
    {
        Expr.pop();
        rch = Figure.top();
        Figure.pop();
        lch = Figure.top();
        Figure.pop();
        switch (ch[t1])
        {
        case '+':
            lch += rch;
            break;
        case '-':
            lch -= rch;
            break;
        case '*':
            lch *= rch;
            break;
        case '/':
            lch /= rch;
            break;
        }
        Figure.push(lch);
    }
    cout << lch << endl;
    return 0;
}