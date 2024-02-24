#include <bits/stdc++.h>
#define For(i, n) for (int i = 0; i < n; i++)
#define For2(i, n) for (int i = 0; i <= n; i++)
using namespace std;
const int k = 1000;
const int y = 1000;
int dp[k][y];
int Knapsack(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0)
        return 0;
    // Check duplicate call or not.
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        // Have two option.

        // Option one
        int op1 = Knapsack(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];

        // Option two
        int op2 = Knapsack(n - 1, weight, value, w);

        // Save and return
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        // Only one option
        // Save and return
        return dp[n][w] = Knapsack(n - 1, weight, value, w);
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int value[n], weight[n];

    // input
    For(i, n)
            cin >>
        weight[i] >> value[i];

    // dp set -1
    For2(i, n)
    {
        For2(j, w)
            dp[i][j] = -1;
    }
    cout << Knapsack(n, weight, value, w) << endl;
    return 0;
}