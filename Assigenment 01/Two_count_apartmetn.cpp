#include <bits/stdc++.h>

using namespace std;
int n, m;
char a[1005][1005];
vector<int> v;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 and j < m and a[i][j] == '.');
}
void dfs(int i, int j, int &ans)
{
    ans++;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    a[i][j] = '#';
    for (int k = 0; k < 4; k++)
    {
        int ci = i + d[k].first;
        int cj = j + d[k].second;
        if (isValid(ci, cj))
        {

            dfs(ci, cj, ans);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                int ans = 0;
                dfs(i, j, ans);
                v.push_back(ans);
            }
        }
    }
    sort(v.begin(), v.end());
    if (v.size() != 0)
    {
        for (int c : v)
        {
            cout << c << " ";
        }
    }
    else
        cout << '0' << endl;
    return 0;
}