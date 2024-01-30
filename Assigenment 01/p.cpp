#include <iostream>

using namespace std;

const int si = 1005;
char a[si][si];
bool vis[si][si];
pair<int, int> st;
pair<int, int> e;
int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#');
}

bool dfs(int i, int j)
{
    if (i == e.first && j == e.second)
    {
        return true;
    }

    vis[i][j] = true;

    int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    for (int k = 0; k < 4; ++k)
    {
        int ni = i + d[k][0];
        int nj = j + d[k][1];

        if (isValid(ni, nj) && !vis[ni][nj])
        {
            if (dfs(ni, nj))
            {
                return true;
            }
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

    if (dfs(st.first, st.second))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
