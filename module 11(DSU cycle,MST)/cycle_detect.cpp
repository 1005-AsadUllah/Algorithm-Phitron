#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int parent[N];
int sz[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int v)
{
    if (parent[v] == -1)
        return v;
    return parent[v] = dsu_find(parent[v]);
}
void dsu_union_by_size(int n1, int n2)
{
    int la = dsu_find(n1);
    int lb = dsu_find(n2);
    if (parent[la] > parent[lb])
    {
        parent[lb] = la;
        sz[la] += sz[lb];
    }
    else
    {
        parent[la] = lb;
        sz[lb] += sz[la];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    bool cy = false;
    dsu_initialize(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int la = dsu_find(a);
        int lb = dsu_find(b);

        if (la == lb)
        {

            cy = true;
        }
        else
        {
            dsu_union_by_size(a, b);
        }
    }

    if (cy)
        cout << "yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}