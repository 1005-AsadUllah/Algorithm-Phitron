#include <bits/stdc++.h>

using namespace std;
int Knapsack(int n, int weight[], int value[], int w)
{
    if (n < 0 || w == 0)
        return 0;
    if (weight[n] <= w)
    {
        // Have two option.

        // Option one
        int op1 = Knapsack(n - 1, weight, value, w - weight[n]) + value[n];

        // Option two
        int op2 = Knapsack(n - 1, weight, value, w);
        return max(op1, op2);
    }
    else
    {
        // Only one option
        return Knapsack(n - 1, weight, value, w);
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int value[n], weight[n];
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    cout << Knapsack(n - 1, weight, value, w) << endl;
    return 0;
}