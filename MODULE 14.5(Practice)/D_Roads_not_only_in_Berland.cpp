#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int s)
{
    if (parent[s] == -1)
        return s;
    int leader = dsu_find(parent[s]);
    parent[s] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main()
{
    int t;
    cin >> t;
    dsu_initialize(t);
    vector<pair<int, int>> cancel;
    vector<pair<int, int>> create;

    for (int i = 1; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            cancel.push_back({a, b});
        }
        else
        {
            dsu_union_by_size(a, b);
        }
    }
    cout << cancel.size() << endl;
    for (int i = 2; i <= t; i++)
    {
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(i);
        if (leaderA != leaderB)
        {
            create.push_back({1, i});
            dsu_union_by_size(1, i);
        }
    }
    for (int i = 0; i < cancel.size(); i++)
    {
        cout << cancel[i].first << " " << cancel[i].second << " " << create[i].first << " " << create[i].second << endl;
    }
    return 0;
}