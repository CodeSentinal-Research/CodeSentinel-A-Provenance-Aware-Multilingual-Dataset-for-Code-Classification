#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, w;
    bool operator<(const edge& b) const {
        return w < b.w;
    }
};

class UnionFind {
private:
    vector<int> par, rank;
public:
    UnionFind(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }

    bool same(int x, int y) {
        x = find(x), y = find(y);
        return x == y;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    int sum = 0;
    for (int i = 0; i < M; i++) {
        edge e = edges[i];
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            sum += e.w;
        }
    }

    cout << sum << "\n";
    return 0;
}