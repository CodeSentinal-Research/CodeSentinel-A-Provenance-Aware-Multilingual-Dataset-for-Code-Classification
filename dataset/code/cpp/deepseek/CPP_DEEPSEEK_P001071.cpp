#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100005];
int vis[100005], c[100005], low[100005], p[100005], n, m, timer, ans;

void dfs(int u) {
    vis[u] = 1;
    low[u] = c[u] = timer++;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!vis[v]) {
            p[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > c[u])
                ans = u;
        } else if (v != p[u] && low[v] < c[u])
            low[u] = min(low[u], c[v]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    if (ans == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}