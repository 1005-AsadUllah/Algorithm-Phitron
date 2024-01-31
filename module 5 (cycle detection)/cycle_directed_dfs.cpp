#include <bits/stdc++.h>

using namespace std;
const int N = 10e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathvisited[N]; // parent r poriborte path track
bool ans;
void dfs(int parent)
{
    vis[parent] = true;
    pathvisited[parent] = true;

    for (auto child : adj[parent])
    {
        if (pathvisited[child]) // path jodi visited hoi tobe ata cycle
            ans = true;
        if (!vis[child])
        {
            dfs(child);
        }
    }
    // kaj sesh tai path false korci.
    pathvisited[parent] = false;
}
int main()
{
    int n,e;
    
    cin >> n >> e;
    while (e--)
    {
        // graph input.
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);

    }
    ans = false;
    for (int i = 0; i < n; i++)// dfs call for every node.
    {
        if (!vis[i]) // Not visited
        {
            // call dfs.
            dfs(i);
        }
    }
    if (ans)// check cycle or not
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}