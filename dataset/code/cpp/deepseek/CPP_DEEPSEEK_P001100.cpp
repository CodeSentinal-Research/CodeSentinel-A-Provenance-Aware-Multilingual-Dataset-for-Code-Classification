#include <iostream>
#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int size) : parent(size, -1), rank(size, 0) {}

    int find(int x) {
        if (parent[x] != -1) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) {
                std::swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

int main() {
    int N, Q;
    std::cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; ++i) {
        int operation, x, y;
        std::cin >> operation >> x >> y;
        if (operation == 1) {
            uf.merge(x, y);
        } else {
            std::cout << (uf.find(x) == uf.find(y) ? "YES\n" : "NO\n");
       
        }
    }

    return 0;
}