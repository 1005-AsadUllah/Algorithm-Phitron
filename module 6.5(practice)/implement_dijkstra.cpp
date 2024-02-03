//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class cmp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        pq.push({S, 0});
        dis[S] = 0;
        while (!pq.empty())
        {
            pair<int, int> parent = pq.top();
            int node = parent.first;
            int cost = parent.second;
            pq.pop();
            for (auto child1 : adj[node])
            {
                int childnode = child1[0];
                int childcost = child1[1];
                if (cost + childcost < dis[childnode])
                {
                    dis[childnode] = cost + childcost;
                    pq.push({childnode, dis[childnode]});
                }
            }
        }
        return dis;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}