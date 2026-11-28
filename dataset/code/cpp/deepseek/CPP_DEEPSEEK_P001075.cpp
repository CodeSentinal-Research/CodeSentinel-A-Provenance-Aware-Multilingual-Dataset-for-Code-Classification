#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

void BellmanFord(vector<Edge>& edges, int N, int S) {
    vector<int> dist(N, numeric_limits<int>::max());
    dist[S] = 0;

    for(int i = 0; i < N-1; ++i) {
        for(auto& e : edges) {
            if(dist[e.u] != numeric_limits<int>::max() && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for(auto& e : edges) {
        if(dist[e.u] != numeric_limits<int>::max() && dist[e.u] + e.w < dist[e.v]) {
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
    }

    for(int i = 0; i < N; ++i) {
        cout << (dist[i] != numeric_limits<int>::max() ? to_string(dist[i]) : "INF") << " ";
    }
    cout << endl;
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    S--;
    vector<Edge> edges;
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back(Edge(u, v, w));
    }
    BellmanFord(edges, N, S);
    return 0;
}

This code first declares a struct Edge to hold the information of an edge in the graph. Then it declares the function BellmanFord which takes the graph and source vertex as input and outputs the shortest distances from the source to all other vertices. The main function reads the graph and source vertex from the standard input, and then calls the BellmanFord function to print the shortest distances.