/**
 *    author:  AsadUllah
 **/
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define For2(i, n) for (int i = 0; i <= n; i++)

using namespace std;
int result(int n, vector<int> &dp, vector<int> &nums, int i)
{
    if (i == 0 or i == 1)
        return nums[i];
    // nile
    if (dp[i] != -1)
        return dp[i];
    int op1 = nums[i] + result(n, dp, nums, i - 2);
    // na nile
    int op2 = result(n, dp, nums, i - 1);
    cout << op1 << " ->" << op2 << endl;
    return dp[i] = max(op1, op2);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 2)
        return max(nums[0], nums[1]);
    vector<int> dp(n + 1, -1);
    return result(n, dp, nums, n - 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    For(i, n)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << rob(nums) << endl;
    return 0;
}