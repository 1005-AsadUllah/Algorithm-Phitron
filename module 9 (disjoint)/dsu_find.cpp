#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
        level[i] = 1;
    }
}
int dsu_find(int v)
{
    if (parent[v] == -1)
        return v;

    int leader = dsu_find(parent[v]);
    parent[v] = leader;
    return leader;
    // return parent[v] = dus_find(parent[v]);
}
void dsu_union_by_size(int v1, int v2)
{
    int leaderA = dsu_find(v1);
    int leaderB = dsu_find(v2);
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

void dsu_union_by_rank(int v1, int v2)
{
    int lA = dsu_find(v1);
    // cout << lA << endl;
    int lB = dsu_find(v2);
    // cout << lB << endl;
    if (level[lA] > level[lB])
    {
        parent[lB] = lA;
    }
    else if (level[lA] < level[lB])
    {
        parent[lA] = lB;
    }
    else
    {
        parent[lA] = lB;
        level[lB]++;
    }
}
int main()
{
    dsu_initialize(7);
    dsu_union_by_rank(1, 2);
    dsu_union_by_rank(2, 3);
    dsu_union_by_rank(4, 5);
    dsu_union_by_rank(5, 6);
    cout << dsu_find(1) << endl;
    dsu_union_by_rank(1, 4);
    cout << dsu_find(1) << endl;

    return 0;
}