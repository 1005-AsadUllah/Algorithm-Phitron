#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[25][25];
char a[25][25];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n || a[i][j] == '#')
        return false;
    return true;
}

void dfs(int si, int sj, int &cnt)
{
    cnt++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj, cnt);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        memset(vis, false, sizeof(vis));
        int si, sj;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }

        int cnt = 0;
        dfs(si, sj, cnt);
        cout << "Case " << i << ": " << cnt << endl;
    }

    return 0;
}
