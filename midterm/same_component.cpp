#include <bits/stdc++.h>
// dfs
using namespace std;
const int N = 10e3 + 5;
int n, m;
char grid[N][N];
bool vis[N][N];
int a = 0;
bool isValid(int i, int j)
{

    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.');
}
bool dfs(int i, int j, int &d1, int &d2)
{
    a++;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    if (i == d1 and j == d2)
        return true;
    vis[i][j] = true;
    for (auto c : d)
    {
        int ci = i + c.first;
        int cj = j + c.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            if (dfs(ci, cj, d1, d2))
                return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int s1, s2, d1, d2;
    cin >> s1 >> s2 >> d1 >> d2;
    memset(vis, false, sizeof(vis));
    bool ans = dfs(s1, s2, d1, d2);

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}