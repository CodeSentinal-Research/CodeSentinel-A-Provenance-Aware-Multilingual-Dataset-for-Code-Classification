Here is the C++ code for the Union-Find problem:

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            uf.unionSet(x, y);
        } else {
            int rootX = uf.find(x);
            int rootY = uf.find(y);
            if (rootX == rootY) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

This code defines a UnionFind class with a constructor that initializes the parent and rank arrays. The find method returns the root of the set containing x, and the unionSet method merges the sets containing x and y. In the main function, we process each operation and print the result for each FIND operation.