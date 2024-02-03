#include <bits/stdc++.h>
#define l long long int
using namespace std;

class Edge
{
public:
    l u, v, c;
    Edge(l u, l v, l c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

vector<l> bellman_ford(vector<Edge> &ed, l n, l s)
{
    vector<l> dis(n + 1, LLONG_MAX);
    dis[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &ch : ed)
        {
            l u = ch.u;
            l v = ch.v;
            l co = ch.c;
            if (dis[u] != LLONG_MAX && dis[u] + co < dis[v])
            {
                dis[v] = co + dis[u];
            }
        }
    }

    for (auto &c : ed)
    {
        l u = c.u;
        l v = c.v;
        l co = c.c;
        if (dis[u] != LLONG_MAX && dis[u] + co < dis[v])
        {
            dis[v] = LLONG_MIN; // Indicate Negative Cycle
        }
    }

    return dis;
}

int main()
{
    l n, e;
    vector<Edge> ed;
    cin >> n >> e;
    while (e--)
    {
        l a, b, c;
        cin >> a >> b >> c;
        ed.push_back(Edge(a, b, c));
    }

    l s;
    cin >> s;

    vector<l> dis = bellman_ford(ed, n, s);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        l des;
        cin >> des;

        if (dis[des] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else if (dis[des] == LLONG_MIN)
            cout << "Negative Cycle Detected" << endl;
        else
            cout << dis[des] << endl;
    }

    return 0;
}
