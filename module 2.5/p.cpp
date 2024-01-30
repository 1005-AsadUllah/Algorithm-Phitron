#include <bits/stdc++.h>

using namespace std;

int n, m;
bool vis_A[1005][1005];
bool vis_B[1005][1005];
char a[1005][1005];
int flag = 0;
pair<int, int> p;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs_B(int si, int sj)
{
    if (a[si][sj] == 'B')
    {
        flag = 1;
    }
    cout << a[si][sj] << endl;
    vis_B[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis_B[ci][cj] && a[ci][cj] == '.')
        {
            dfs_B(ci, cj);
        }
    }
}

pair<int, int> dfs_A(int si, int sj)
{
    if (a[si][sj] == 'A')
    {
        p = {si, sj};
    }
    vis_A[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis_A[ci][cj] && a[ci][cj] == '.')
        {
            dfs_A(ci, cj);
        }
    }
    return p;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    // pair<int, int> start = dfs_A(0, 0);
    dfs_B(1, 2);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
