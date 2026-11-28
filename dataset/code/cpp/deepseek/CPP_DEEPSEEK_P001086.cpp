#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

vector<int> shortestDistance(vector<Edge> edges, int sources[], int n) {
    vector<int> distance(n, INT_MAX);
    distance[sources[0]] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, sources[0]});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d == distance[u]) {
            for (auto &edge : edges) {
                if (u == edge.u && d + edge.w < distance[edge.v]) {
                    distance[edge.v] = d + edge.w;
                    pq.push({distance[edge.v], edge.v});
                }
            }
        }
    }

    return distance;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    int sources[k];
    for (int i = 0; i < k; i++) {
        cin >> sources[i];
        sources[i]--;
    }

    vector<int> distance = shortestDistance(edges, sources, n);
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << "INF";
        } else {
            cout << distance[i];
        }
        cout << " ";
    }
    cout << "\n";

    return 0;
}