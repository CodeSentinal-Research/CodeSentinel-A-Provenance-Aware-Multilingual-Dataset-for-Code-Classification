#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    int reachable_count = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            reachable_count++;
        }
    }

    cout << reachable_count << endl;

    return 0;
}