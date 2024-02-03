#include <bits/stdc++.h>
using namespace std;

int vis[1000] = {0};
class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool detect(int i, vector<int> adj[])
    {
        vis[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            for (auto adjacent : adj[node])
            {
                if (!vis[adjacent])
                {
                    vis[adjacent] = 1;
                    q.push({adjacent, node});
                }
                else if (adjacent != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}