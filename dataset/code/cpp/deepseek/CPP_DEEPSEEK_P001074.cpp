#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> distances(N + 1, INT_MAX);
    distances[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        for (const Edge& edge : graph[currentVertex]) {
            int destination = edge.destination;
            int weight = edge.weight;

            if (distances[destination] > currentDistance + weight) {
                distances[destination] = currentDistance + weight;
                pq.push({distances[destination], destination});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << (distances[i] == INT_MAX ? -1 : distances[i]) << " ";
    }
    cout << endl;

    return 0;
}
This code uses Dijkstra's algorithm to find the shortest path in a weighted graph from a source vertex. The source vertex is inputted through the first line, followed by the total number of edges and the edges themselves. The edges are processed and the shortest distances from the source to each vertex are calculated. If a vertex has no connection with the source, its distance is set to -1.