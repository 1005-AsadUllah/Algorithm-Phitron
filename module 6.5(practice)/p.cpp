#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int n, int s, int f, vector<vector<int>> &graph)
{
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s - 1] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr_vertex = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr_vertex - 1])
        {
            continue;
        }

        for (int neighbor = 0; neighbor < n; ++neighbor)
        {
            if (graph[curr_vertex - 1][neighbor] != -1 &&
                dist[curr_vertex - 1] + graph[curr_vertex - 1][neighbor] < dist[neighbor])
            {
                dist[neighbor] = dist[curr_vertex - 1] + graph[curr_vertex - 1][neighbor];
                pq.push({dist[neighbor], neighbor + 1});
            }
        }
    }

    int shortest_path = dist[f - 1];
    if (shortest_path == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << shortest_path << endl;
    }
}

int main()
{
    int n, s, f;
    cin >> n >> s >> f;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    dijkstra(n, s, f, graph);

    return 0;
}
