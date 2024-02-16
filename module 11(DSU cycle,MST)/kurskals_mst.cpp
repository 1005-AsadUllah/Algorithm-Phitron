#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int parent[N];
int sz[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int v)
{
    if (parent[v] == -1)
        return v;
    return parent[v] = dsu_find(parent[v]);
}
void dsu_union_by_size(int n1, int n2)
{
    int la = dsu_find(n1);
    int lb = dsu_find(n2);
    if (parent[la] > parent[lb])
    {
        parent[lb] = la;
        sz[la] += sz[lb];
    }
    else
    {
        parent[la] = lb;
        sz[lb] += sz[la];
    }
}
class Edge
{
public:
    int v;
    int u;
    int c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> edgelist;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgelist.push_back(Edge(a, b, c));
    }
    int cost = 0;
    sort(edgelist.begin(), edgelist.end(), cmp);
    for (Edge ed : edgelist)
    {
        int la = dsu_find(ed.u);
        int lb = dsu_find(ed.v);
        if (la != lb)
        {
            dsu_union_by_size(ed.u, ed.v);
            cost += ed.c;
        }
    }
    // for (Edge ed : edgelist)
    //     cout << ed.u << " " << ed.v << " " << ed.c << endl;
    cout << cost << endl;
    return 0;
}