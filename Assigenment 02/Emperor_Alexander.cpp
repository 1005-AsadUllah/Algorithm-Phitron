#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll parent[N];
ll sz[N];
void dsu_initialize(ll n)
{
    for (ll i = 0; i < n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}
ll dsu_find(ll v)
{
    if (parent[v] == -1)
        return v;
    return parent[v] = dsu_find(parent[v]);
}
void dsu_union_by_size(ll n1, ll n2)
{
    ll la = dsu_find(n1);
    ll lb = dsu_find(n2);
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
    ll v;
    ll u;
    ll c;
    Edge(ll u, ll v, ll c)
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
    ll n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> edgelist;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edgelist.push_back(Edge(a, b, c));
    }
    ll cost = 0;
    ll cnt = 0;
    sort(edgelist.begin(), edgelist.end(), cmp);
    for (Edge ed : edgelist)
    {
        ll la = dsu_find(ed.u);
        ll lb = dsu_find(ed.v);
        if (la != lb)
        {
            dsu_union_by_size(ed.u, ed.v);
            cost += ed.c;
        }
        else
        {
            cnt++;
        }
    }
    bool connected = true;
    for (ll i = 2; i <= n; i++)
    {
        if (dsu_find(i) != dsu_find(1))
        {
            connected = false;
            break;
        }
    }
    if (connected)
        cout << cnt << " " << cost << endl;
    else
        cout << "Not Possible" << endl;
    return 0;
}
