#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int N) : parent(N, -1) {}
    int find(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (parent[x] < parent[y]) swap(x, y);
        parent[x] += parent[y], parent[y] = x;
    }
    bool same(int x, int y) {
        x = find(x), y = find(y);
        return x == y;
    }
};

int main() {
    int N;
    cin >> N;
    UnionFind uf(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a - 1, b - 1);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (uf.find(i) == uf.find(j)) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}