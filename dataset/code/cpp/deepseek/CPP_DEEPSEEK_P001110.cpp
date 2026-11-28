#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> colors;
vector<bool> used;
vector<vector<int>> edges;

bool dfs(int v, int c) {
    colors[v] = c;
    used[c] = true;

    for (int u : edges[v]) {
        if (!colors[u] && !used[c]) {
            if (dfs(u, c)) {
                return true;
            }
        }
    }

    return false;
}

bool canColor(int N, int M) {
    colors.assign(N, -1);
    used.assign(M, false);
    edges.assign(N, vector<int>());

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (!colors[i] && !used[0]) {
            if (dfs(i, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N, E, M;
    cin >> N >> E >> M;
    cout << (canColor(N, M) ? "YES" : "NO") << endl;
    return 0;
}