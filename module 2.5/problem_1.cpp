#include <bits/stdc++.h>

using namespace std;
vector<int> v[10005];
bool vis[10005];
int level[10005];
int parent[10005];
int bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int par = p.first;
        int le = p.second;
        q.pop();

        if (par == des)
        return le;
        for (int child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push({child, le + 1});
                parent[child] = par;
            }
        }
    }
    return -1;
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src;
        int des;
        cin >> src >> des;
        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        memset(level, -1, sizeof(level));
        int path = bfs(src, des);
        cout << path << endl;
    }
    return 0;
}