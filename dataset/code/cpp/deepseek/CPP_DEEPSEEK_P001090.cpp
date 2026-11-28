#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, diameter = -1;
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    int max1 = 0, max2 = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) {
            dfs(v);
            if (1 + dfs(v) > max1) {
                max2 = max1;
                max1 = dfs(v);
            } else if (1 + dfs(v) > max2) {
                max2 = dfs(v);
            }
        }
    }
    diameter = max(diameter, max1 + max2 + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << diameter << endl;
    return 0;
}