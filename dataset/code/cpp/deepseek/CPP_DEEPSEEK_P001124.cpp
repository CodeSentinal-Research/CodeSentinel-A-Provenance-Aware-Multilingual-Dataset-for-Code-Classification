#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Flight {
    int u, v, cost;

    bool operator<(const Flight& f) const {
        return cost < f.cost;
    }
};

int main() {
    int N, M, S, D, K;
    cin >> N >> M >> S >> D >> K;

    vector<vector<int>> graph(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u][v] = cost;
    }

    vector<int> dist(N, INT_MAX);
    dist[S] = 0;

    priority_queue<Flight> pq;
    pq.push({S, D, 0});

    while (!pq.empty()) {
        Flight f = pq.top();
        pq.pop();

        if (f.cost > dist[f.v]) continue;

        for (int i = 0; i < N; i++) {
            int cost = f.cost + graph[f.u][i];
            if (cost < dist[i]) {
                dist[i] = cost;
                pq.push({f.u, i, cost});
            }
        }
    }

    if (dist[D] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[D] << endl;
    }

    return 0;
}