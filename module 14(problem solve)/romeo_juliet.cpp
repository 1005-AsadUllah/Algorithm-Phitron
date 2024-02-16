#include <bits/stdc++.h>

using namespace std;
const int N = 10e5 + 5;
vector<int> adj[N];
bool vis[N];
int dis[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int child : adj[p])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[p] + 1;
            }
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        dis[i] = -1;
    }
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s, d, c;
    cin >> s >> d >> c;
    bfs(s);
    if (dis[d] != -1 and dis[d] <= (c * 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}