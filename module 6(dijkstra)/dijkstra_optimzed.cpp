#include <bits/stdc++.h>

// time complexity :-> O(V+E)* E log V.

using namespace std;
const int N = 100;
vector<pair<int, int>> adj[N]; // node ar cost thakbe.
int dis[N];                    //  Determine the cost.
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
        int node = parent.first;
        int cost = parent.second;
        q.pop();
        for (auto child : adj[node])
        {
            int childnode = child.first;

            int childcost = child.second;
            // path relaxation check..
            if (cost + childcost < dis[childnode])
            {

                dis[childnode] = cost + childcost;

                q.push({childnode, cost + childcost});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        // assign infinity value;
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }
    return 0;
}