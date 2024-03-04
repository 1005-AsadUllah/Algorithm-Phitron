/**
 *    author:  AsadUllah
 **/
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define For2(i, n) for (int i = 0; i <= n; i++)

using namespace std;
int main()
{
    int n, dif;
    cin >> n;
    int a[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    cin >> dif;
    if (s % 2 == 0 and dif % 2 != 0)
    {
        cout << "Not Possible" << endl;
        return 0;
    }
    int s1 = (s + dif) / 2;
    int dp[n + 1][s1 + 1];
    // cout << s1 << endl;
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s1] << endl;
    return 0;
}