#include <bits/stdc++.h>
#define l long long
using namespace std;
const l N = 1e18;

int main()
{
    l n, e;
    cin >> n >> e;
    l adj[n][n];
    l dis[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INT_MAX;
        }
    }
    while (e--)
    {
        l a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    return 0;
}