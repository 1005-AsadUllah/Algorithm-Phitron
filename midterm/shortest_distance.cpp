#include <bits/stdc++.h>
// floyd warshell
#define l long long
using namespace std;
const l N = 1004;
l d[N][N];
void floyd_warshell(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < 1e18 && d[k][j] < 1e18 && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}
int main()
{
    l n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 1e18;
        }
    }

    while (e--)
    {
        l a, b, c;
        cin >> a >> b >> c;
        if (d[a][b] > c)
            d[a][b] = (c);
    }
    floyd_warshell(n);
    l t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a][b] == 1e18)
            cout << "-1" << endl;
        else
            cout << d[a][b] << endl;
    }
    return 0;
}
