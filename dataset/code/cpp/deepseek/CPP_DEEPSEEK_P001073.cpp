#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator< (const Edge& other) const {
        return w < other.w;
    }
};

int findParent(int u, vector<int>& parent) {
    if(parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v])
        swap(u, v);
    parent[v] = u;
    if(rank[u] == rank[v])
        rank[u]++;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> parent(N+1), rank(N+1, 0);
    for(int i=0; i<N; i++)
        parent[i] = i;

    priority_queue<Edge> pq;

    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push(Edge(u, v, w));
    }

    int mst_weight = 0;
    while(!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        int u = edge.u, v = edge.v, w = edge.w;
        if(findParent(u, parent) != findParent(v, parent)) {
            unionn(u, v, parent, rank);
            mst_weight += w;
        }
    }

    cout << mst_weight << "\n";

    return 0;
}