#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
char a[N][N];
int cnt = INT_MAX;
int n, m;
bool vis[N][N];
int co = 0;
vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '-' && !vis[i][j]);
}
void dfs(int si, int sj)
{
    co++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (!vis[i][j] && a[i][j] != '-')
            {
                co = 0;
                dfs(i, j);
                if (co < cnt)
                {
                    cnt = co;
                }
            }
        }
    }
    if (cnt == INT_MAX)
        cout << -1 << endl;
    else
        cout << cnt << endl;
    return 0;
}