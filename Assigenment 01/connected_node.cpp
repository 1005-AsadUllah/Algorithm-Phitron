#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src;
        cin >> src;
        sort(v[src].begin(), v[src].end(), greater<int>());
        if (v[src].size() == 0)
            cout << "-1" << endl;
        else
        {
            for (auto child : v[src])
                cout << child << " ";
            cout << endl;
        }
    }
    return 0;
}