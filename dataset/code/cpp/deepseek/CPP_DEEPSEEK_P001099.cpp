#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int size) : parent(size, -1) {}

    int find(int x) {
        if (parent[x] == -1)
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            parent[y] = x;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.merge(a - 1, b - 1);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (uf.find(a - 1) == uf.find(b - 1)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}