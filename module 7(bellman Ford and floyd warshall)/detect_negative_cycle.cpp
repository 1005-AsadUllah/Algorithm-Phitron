#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 100;
int dis[N];
int main()
{
    vector<Edge *> Edgelist;
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge *ed_direct = new Edge(a, b, c);
        // Edge *ed_undirect = new Edge(b, a, c);
        Edgelist.push_back(ed_direct);
        // Edgelist.push_back(ed_undirect);
    }
    for (int i = 1; i < n; i++)
        dis[i] = INT_MAX;
    dis[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (Edge *ed : Edgelist)
        {
            int u = ed->u;
            int v = ed->v;
            int c = ed->c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool flag = false;
    for (Edge *ed : Edgelist)
    {
        int u = ed->u;
        int v = ed->v;
        int c = ed->c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            flag = true;
            dis[v] = dis[u] + c;
        }
    }
    if (flag)
        cout << "Cycle detect" << endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << "->" << dis[i] << endl;
    }
    for (Edge *ed : Edgelist)
        delete ed;

    return 0;
}