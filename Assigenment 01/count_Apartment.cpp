#include <bits/stdc++.h>

using namespace std;
const int si = 1005;
int n, m;
char a[si][si];
bool isValid(int i, int j)
{
    
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.');
}
void dfs(int i, int j)
{
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    a[i][j] = '#';
    for (int k = 0; k < 4; k++)
    {
        int ci = i + d[k].first;
        int cj = j + d[k].second;
        if (isValid(ci, cj))
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
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                ans++;
                // cout << i << "->" << j << endl;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}