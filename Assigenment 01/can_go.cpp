#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> a;
vector<vector<bool>> vis;
pair<int, int> st;
pair<int, int> e;
int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#');
}

bool canReach()
{
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    queue<pair<int, int>> q;
    q.push(st);
    vis[st.first][st.second] = true;

    while (!q.empty())
    {
        pair<int, int> cu = q.front();
        q.pop();

        if (cu == e)
        {
            return true;
        }

        for (const auto di : d)
        {
            int ni = cu.first + di.first;
            int nj = cu.second + di.second;

            if (isValid(ni, nj) && !vis[ni][nj])
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                st = {i, j};
            }
            else if (a[i][j] == 'B')
            {
                e = {i, j};
            }
        }
    }

    if (canReach())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
