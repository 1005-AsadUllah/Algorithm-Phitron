	#include <bits/stdc++.h>

using namespace std;
// time complexity = 
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
        Edge *ed = new Edge(a, b, c);
        Edgelist.push_back(ed);
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
    for (int i = 0; i < n; i++)
        cout << i << "->" << dis[i] << endl;
    for (Edge *ed : Edgelist)
        delete ed;

    return 0;
}
