#include <bits/stdc++.h>
// bellman ford
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
int main()
{
    l n, e;
    vector<Edge> ed;
    l dis[1005];
    cin >> n >> e;
    while (e--)
    {
        l a, b, c;
        cin >> a >> b >> c;
        ed.push_back(Edge(a, b, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }

    l s;
    cin >> s;
    dis[s] = 0;
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        for (auto ch : ed)
        {
            l u = ch.u;
            l v = ch.v;
            l co = ch.c;
            if (dis[u] < 1e18 and dis[u] + co < dis[v])
            {
                dis[v] = co + dis[u];
            }
        }
    }
    for (auto c : ed)
    {
        l u = c.u;
        l v = c.v;
        l co = c.c;
        if (dis[u] < 1e18 and dis[u] + co < dis[v])
        {
            ans = true;
            dis[v] = co + dis[u];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        l des;
        cin >> des;
        if (dis[des] == 1e18)
            cout << "Not Possible" << endl;
        else if (ans == true)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else
            cout << dis[des] << endl;
    }

    return 0;
}