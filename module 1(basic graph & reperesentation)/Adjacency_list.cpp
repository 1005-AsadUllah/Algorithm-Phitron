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
        // if write two line this is undirected graph.otherwise write first line only this is directed graph.
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < v[1].size(); i++)
        cout << v[1][i] << " ";
    cout << endl;
    for (int x : v[0])
        cout << x << " ";
    return 0;
}