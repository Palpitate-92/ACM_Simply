//动态链表实现---动态分配节点
/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;
struct edge{
    int nodeid;
    int edge_value;
    edge *next;
};
struct{
    edge *next;
} mynode[MAXN];
int main()
{
    int n, m, u, v, w;
    edge *newedge;
    scanf("%d%d", &n, &m);
    memset(mynode, 0, sizeof(mynode));
    for (int i = 0; i < m;i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        newedge = new edge;//建新边
        newedge->nodeid = v;//记录边的一个端点
        newedge->edge_value = w;//记录边权
        newedge->next = mynode[u].next;//插入到u的邻接边中
        mynode[u].next = newedge;
        //若是无向图，则有对称边
        newedge = new edge;//建新边
        newedge->nodeid = u;//记录边的一个端点
        newedge->edge_value = w;//记录边权
        newedge->next = mynode[v].next;//插入到u的邻接边中
        mynode[v].next = newedge;
    }
    //其他操作
    return 0;
}
*/
//vector实现
//无权图
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    vector<vector<int>> mynode(n); //< <
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        mynode[u].push_back(v);
        //mynode[v].push_back(u);//无向图需要加上
    }
    for (int i = 0; i < n; i++)
    {
        int k = mynode[i].size();
        printf("%d-%d:", i, k);
        for (int j = 0; j < k; j++)
            printf("%d ", mynode[i][j]);
        puts("");
    }
    return 0;
}
*/
//赋权图
/*
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int nodeid;
    int value;
};
int main()
{
    int n, m, u, v, w;
    edge temp;
    scanf("%d%d", &n, &m);
    vector<vector<edge>> mynode(n); //< <
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        temp.nodeid = v;
        temp.value = w;
        mynode[u].push_back(temp);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < mynode[i].size(); j++)
        {
            printf("%d-%d(%d)", i, mynode[i][j].nodeid, mynode[i][j].value);
            puts("");
        }
    return 0;
}
*/
//静态链表
/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXM = 1000;
//本例代码针对有向图
int main()
{
    int n, m, u, v;
    int node[MAXN];
    int id[MAXM], w[MAXM], next[MAXM];
    memset(node, -1, sizeof(node)); //-1代表空指针
    memset(next, -1, sizeof(next));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w[i]);
        id[i] = v;
        next[i] = node[u];
        node[u] = i;
    }
    //其他操作
    //假设要遍历节点u的所有邻接边
    int e = node[u];
    while (e != -1)
    {
        printf("%d", w[e]);
        e = next[e];
    }
    return 0;
}
*/
//动态链表实现---静态分配节点
/*
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXM 1000
struct edge
{
    int nodeid;
    int edge_value;
    struct edge *next;
} newedge[MAXM];
struct node
{ //int node_value;
    struct edge *next;
} mynode[MAXN];
int main()
{
    int k = 0, n, m, u, v, w;
    scanf("%d%d", &n, &m);
    memset(mynode, 0, sizeof(mynode));
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        newedge[k].nodeid = v;
        newedge[k].edge_value = w;
        newedge[k].next = mynode[u].next;
        mynode[u].next = &newedge[k];
        k++; //若是无向图，则
        newedge[k].nodeid = u;
        newedge[k].edge_value = w;
        newedge[k].next = mynode[v].next;
        mynode[v].next = &newedge[k];
        k++;
    }
    //其它操作
    //假设要遍历结点u的所有邻接边
    struct edge *e = mynode[u].next;
    while (e != NULL)
    {
        printf("%d ", e->edge_value);
        e = e->next;
    }
    return 0;
}
*/