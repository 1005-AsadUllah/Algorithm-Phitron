#include <bits/stdc++.h>

using namespace std;
int n, m, ki, kj, qi, qj;
vector<pair<int, int>> d = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

bool isValid(int i, int j, vector<vector<int>> &grid)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == -1);
}
int knight(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    grid[ki][kj] = 0;
    q.push({ki, kj});
    if (ki == qi && kj == qj)
        return 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int i = parent.first;
        int j = parent.second;
        for (int k = 0; k < 8; k++)
        {
            int ci = i + d[k].first;
            int cj = j + d[k].second;
            if (isValid(ci, cj, grid))
            {
                grid[ci][cj] = grid[i][j] + 1;
                q.push({ci, cj});
                if (ci == qi && cj == qj)
                    return grid[ci][cj];
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));

        cin >> ki >> kj >> qi >> qj;
        int ans = knight(grid);
        cout << ans << endl;
    }
    return 0;
}