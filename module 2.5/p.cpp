#include <bits/stdc++.h>
using namespace std;

vector<int> v[10005];
int level[10005];
bool vis[10005];

void bfs(int le, vector<int> &v1) {
    queue<int> q;
    q.push(0);
    level[0] = 0;
    vis[0] = true;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        if (level[parent] == le) {
            v1.push_back(parent);
        }

        for (auto child : v[parent]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int le;
    cin >> le;

    memset(level, -1, sizeof(level));
    memset(vis, false, sizeof(vis));

    vector<int> v1;
    bfs(le, v1);

    sort(v1.begin(), v1.end(), greater<int>());

    for (auto val : v1) {
        cout << val << " ";
    }

    return 0;
}
