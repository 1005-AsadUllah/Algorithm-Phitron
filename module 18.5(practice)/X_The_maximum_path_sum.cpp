/**
 *    author:  AsadUllah
 **/
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define For2(i, n) for (int i = 0; i <= n; i++)

using namespace std;
const int N = 15;
int n, m;
int a[N][N];
int dp[N][N];
bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}
int result(int i, int j)
{
    // base case
    if (i == n - 1 and j == m - 1)
        return a[i][j];

    // I have two option
    if (dp[i][j] != -1)
        return dp[i][j];
    int op1 = INT_MIN, op2 = INT_MIN;

    if (isValid(i + 1, j))
        op1 = result(i + 1, j);
    if (isValid(i, j + 1))
        op2 = result(i, j + 1);

    return dp[i][j] = max(op1, op2) + a[i][j];
}
int main()
{

    cin >> n >> m;

    For(i, n)
    {
        For(j, m)
                cin >>
            a[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << result(0, 0) << endl;
    return 0;
}