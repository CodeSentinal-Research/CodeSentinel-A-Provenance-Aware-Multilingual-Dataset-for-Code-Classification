#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n, m;
vector<int> g[MAXN];
bool vis[MAXN];

void dfs(int v) {
    vis[v] = true;
    for (int u : g[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    bool isTree = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            isTree = false;
            break;
        }
    }
    if (isTree) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}