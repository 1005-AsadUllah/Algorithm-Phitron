#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int flag = 0;
        int k, l;
        cin >> k >> l;

        for (auto c : v[k])
        {
            if (c == l)
                flag = 1;
        }
        if (flag)
            cout << "YES" << endl;
        else if (l == k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}