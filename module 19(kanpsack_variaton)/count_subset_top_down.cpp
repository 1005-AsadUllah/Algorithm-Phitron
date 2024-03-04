/**
 *    author:  AsadUllah
 **/
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define For2(i, n) for (int i = 0; i <= n; i++)

using namespace std;
int dp[1005][1005];

int subset(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    if (a[n - 1] <= s)
    {
        int op1 = subset(n - 1, a, s - a[n - 1]);

        int op2 = subset(n - 1, a, s);

        return dp[n][s] = op1 + op2;
    }
    else
    {
        return dp[n][s] = subset(n - 1, a, s);
    }
}
int main()
{
    int n, s;
    cin >> n;
    int a[n];
    For(i, n)
    {
        cin >> a[i];
    }
    cin >> s;
    For(i, n + 1)
    {
        For(j, s + 1)
            dp[i][j] = -1;
    }
    cout << subset(n, a, s);

    return 0;
}