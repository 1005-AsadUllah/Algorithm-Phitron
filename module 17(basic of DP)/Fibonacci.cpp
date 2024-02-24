
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fibo(ll n)
{
    if (n == 0 || n == 1)
        return n;

    ll ans = fibo(n - 1) + fibo(n - 2);
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}