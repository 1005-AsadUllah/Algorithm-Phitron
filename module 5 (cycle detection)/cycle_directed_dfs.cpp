#include <bits/stdc++.h>

using namespace std;
const int N = 10e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathvisited[N];
bool ans;
void dfs(int parent)
{
    vis[parent] = true;
    pathvisited[parent] = true;

    for (auto child : adj[parent])
    {
        if (pathvisited[child])
            ans = true;
        if (!vis[child])
        {
            dfs(child);
        }
    }
    // kaj sesh
    pathvisited[parent] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}