Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000000;

int maxFlow(int source, int sink, int n, vector<vector<int>> &adj, vector<int> &parent, vector<int> &level) {
    int maxFlow = 0;

    while (true) {
        queue<int> q;
        q.push(source);
        parent[source] = -1;
        level[source] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (level[u] + 1 == level[v] && capacity[u][v] > 0) {
                    int curFlow = min(capacity[u][v], level[sink] - level[u]);
                    capacity[u][v] -= curFlow;
                    capacity[v][u] += curFlow;
                    q.push(v);
                    parent[v] = u;

                    if (v == sink) {
                        return maxFlow;
                    }
                }
            }
        }

        if (parent[sink] == -1) {
            return maxFlow;
        }

        int flow = INF;

        for (int i = sink; parent[i] != -1; i = parent[i]) {
            flow = min(flow, capacity[parent[i]][i]);
        }

        maxFlow += flow;

        for (int i = sink; parent[i] != -1; i = parent[i]) {
            capacity[parent[i]][i] += flow;
            capacity[i][parent[i]] -= flow;
        }
    }
}

int main() {
    int n, m, source, sink;

    cin >> n >> m >> source >> sink;

    vector<vector<int>> adj(n);
    vector<int> capacity(n, vector<int>(n, 0));
    vector<int> parent(n, -1);
    vector<int> level(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        adj[u].push_back(v);
        capacity[u][v] = cap;
    }

    cout << maxFlow(source, sink, n, adj, parent, level) << endl;

    return 0;
}

This code first reads the number of vertices, edges, source and sink. Then it reads the capacities of the edges. The capacity of an edge from vertex u to vertex v is stored in the capacity[u][v] and capacity[v][u] array. After setting all capacities, it uses the Edmonds-Karp algorithm to find the maximum flow from the source to the sink. The algorithm uses a queue to process the edges in the graph in a breadth-first manner. For each vertex, if there is a path from the source to that vertex with capacity greater than 0, then the maximum flow is updated. The maximum flow is then added to the total flow and the capacities of the edges are updated accordingly. The process continues until no path from the source to the sink is found.