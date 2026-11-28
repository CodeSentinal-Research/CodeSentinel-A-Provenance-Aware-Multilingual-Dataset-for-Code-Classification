#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int dest, weight;
};

vector<Edge> graph[100005];
int dist[100005];
bool visited[100005];

void shortestPath(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int source_vertex = pq.top().second;
        int source_distance = pq.top().first;
        pq.pop();

        if (source_distance != dist[source_vertex])
            continue;

        for (int i = 0; i < graph[source_vertex].size(); i++) {
            Edge e = graph[source_vertex][i];
            int dest = e.dest;
            int edge_distance = e.weight;

            if (dist[source_vertex] + edge_distance < dist[dest]) {
                dist[dest] = dist[source_vertex] + edge_distance;
                pq.push({dist[dest], dest});
            }
        }
    }
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }
    dist[S] = 0;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] != INT_MAX) {
            cout << dist[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}

The code above uses the Dijkstra's algorithm to find the shortest distance from the source vertex to all other vertices in the graph. It first initializes the distance to each vertex to infinity except the source vertex to 0. Then it enters a loop where it pops the vertex with the smallest distance and relaxes all edges that have shorter distances.