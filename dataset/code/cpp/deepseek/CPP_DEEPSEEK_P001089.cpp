#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
int degree[MAXN];
int N;

void bfs() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';

        for (int u : adj[v]) {
            if (--degree[u] == 1) {
                q.push(u);
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    bfs();

    return 0;
}