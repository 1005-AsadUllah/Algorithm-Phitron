#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
int a[N][N];
int dis[N];
vector<pair<int, int>> v[N];
class cmp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.top();
        q.pop();
        int node = parent.first;
        int cost = parent.second;
        for (auto c : v[node])
        {
            int cn = c.first;
            int cc = c.second;
            if (cost + cc < dis[cn])
            {
                dis[cn] = cost + cc;
                q.push({cn, dis[cn]});
            }
        }
    }
}

int main()
{

    int n, s, f;
    cin >> n >> s >> f;
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] > 0)
            {
                v[i].push_back({j, a[i][j]});
            }
        }
    }
    dijkstra(s);
    if (dis[f] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[f] << endl;
    }

    return 0;
}