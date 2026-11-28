Here is the code for the problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

struct comp {
    bool operator()(edge a, edge b) {
        return a.w > b.w;
    }
};

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    vector<edge> edges(M);
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = edge(u, v, w);
    }
    vector<int> dist(N+1, -1);
    dist[S] = 0;
    priority_queue<edge, vector<edge>, comp> pq;
    for(int i = 0; i < M; i++) {
        pq.push(edges[i]);
    }
    while(!pq.empty()) {
        edge curr = pq.top(); pq.pop();
        if(dist[curr.v] == -1 or dist[curr.v] > dist[curr.u] + curr.w) {
            dist[curr.v] = dist[curr.u] + curr.w;
            for(int i = 0; i < M; i++) {
                if(edges[i].u == curr.u) {
                    pq.push(edges[i]);
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(dist[i] == -1) {
            cout << "-1" << endl;
            return 0;
        }
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}

This code uses a priority queue to handle the edges in descending order of weights. The priority queue is used to ensure that the edge with the smallest weight is processed first. The distance array stores the minimum delay time from the source node to each other node. If a node cannot be reached, its distance is set to -1.