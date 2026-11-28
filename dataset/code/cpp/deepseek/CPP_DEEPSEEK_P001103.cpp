#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class UnionFind {
private:
    vector<int> p;

public:
    UnionFind(int N) {
        p.resize(N);
        for(int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        if(p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        p[x] = y;
    }
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(N);
    vector<int> component(N);
    for(int i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(uf.find(u) != uf.find(v)) {
            cout << u << " " << v << "\n";
            uf.unite(u, v);
            component[uf.find(u)] = 1;
        }
    }
    bool exist = false;
    for(int i = 0; i < N; i++) {
        if(!component[i]) {
            exist = true;
            cout << i << " " << N << "\n";
        }
    }
    if(!exist) {
        cout << "NONE\n";
    }
    return 0;
}