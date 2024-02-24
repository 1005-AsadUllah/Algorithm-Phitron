/**
 *    author:  AsadUllah
 **/
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define For2(i, n) for (int i = 0; i <= n; i++)
#define l long long
using namespace std;

bool a = false;
void result(l &n, l k)
{
    if (k > n)
        return;
    if (k == n)
    {
        a = true;
    }
    // I have two option
    result(n, k * 10);
    result(n, k * 20);
}
int main()
{
    l t;
    cin >> t;
    while (t--)
    {
        l n;
        cin >> n;
        l k = 1;
        result(n, k);
        if (a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        a = false;
    }
    return 0;
}