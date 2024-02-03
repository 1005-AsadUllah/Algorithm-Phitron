#include <bits/stdc++.h>
#define ll long long
using namespace std;
// dijkstra
long long dis[100005];
vector<pair<ll, ll>> adj[100005];
class cmp
{
public:
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {
        return a.first > b.first;
    }
};
void dijkstra(ll s)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty())
    {
        ll node = q.top().first;
        ll cost = q.top().second;
        q.pop();
        for (auto c : adj[node])
        {
            ll cn = c.first;
            ll cc = c.second;
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

    ll n, e;
    cin >> n >> e;
    for (ll i = 1; i <= n; i++)
        dis[i] = INT_MAX;

    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    ll s, t;
    cin >> s >> t;
    dijkstra(s);
    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << endl;
    while (t--)
    {
        ll d, c;
        cin >> d >> c;
        if (dis[d] <= c)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}