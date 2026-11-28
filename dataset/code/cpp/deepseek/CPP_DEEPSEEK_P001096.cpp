#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    vector<vector<pair<int, int>>> graph(N);
    vector<int> capacity(N, 0);
    vector<int> dist(N, INT_MAX);
    vector<int> parent(N, -1);

    for (int i = 0; i < M; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        graph[u].push_back({v, cap});
        graph[v].push_back({u, cap});
        capacity[u] += cap;
        capacity[v] += cap;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &i : graph[u]) {
            int v = i.first;
            int cap = i.second;

            if (capacity[u] > 0 && dist[u] + cap < dist[v]) {
                dist[v] = dist[u] + cap;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[T] == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[T] << '\n';
    }

    return 0;
}