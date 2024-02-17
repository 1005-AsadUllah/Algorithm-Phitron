#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int n, m;
const int N = 1e3 + 5;
char a[N][N];
pi s, des;
bool vis[N][N];
map<pi, pi> mp;
vector<pi> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#');
}
void bfs(pi s)
{
    queue<pi> q;
    q.push({s.first, s.second});
    // cout << q.front().first << endl;
    vis[s.first][s.second] = true;
    mp[{s.first, s.second}] = {-1, -1};
    while (!q.empty())
    {
        pi par = q.front();
        int p = par.first;
        int p1 = par.second;
        // cout << p << " " << p1 << endl;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = p + d[i].first;
            int cj = p1 + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                mp[{ci, cj}] = {p, p1};
            }
        }
    }
}
void path(pi dest, pi src)
{
    while (dest != src)
    {
        a[dest.first][dest.second] = 'X';
        dest = mp[dest];
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
            if (a[i][j] == 'D')
            {
                des = {i, j};
                mp[{des.first, des.second}] = {-1, -1};
            }
            if (a[i][j] == 'R')
                s = {i, j};
        }
    }
    // cout << s.first << " " << s.second << endl;
    bfs(s);
    if (mp[{des.first, des.second}] == make_pair(-1, -1))

    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        path(des, s);
        a[des.first][des.second] = 'D';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}