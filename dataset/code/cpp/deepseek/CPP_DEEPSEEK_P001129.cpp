Sure, here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, type;
    bool operator < (const Edge& b) const {
        return type < b.type;
    }
};

vector<int> p, rank;

int findset(int x) {
    if (p[x] != x) p[x] = findset(p[x]);
    return p[x];
}

void unite(int x, int y) {
    x = findset(x); y = findset(y);
    if (x != y) {
        if (rank[x] < rank[y]) swap(x, y);
        p[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int max_edges(int N, int M, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    p.resize(N + 1);
    rank.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) p[i] = i;
    int Alice = N, Bob = 0, count = 0;
    for (int i = 0; i < M; i++) {
        if (findset(edges[i].u) != findset(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            if (findset(edges[i].u) == Alice) Alice--;
            else Bob++;
            count++;
        }
    }
    if (Alice == 1 && Bob == 1) return count;
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].type >> edges[i].u >> edges[i].v;
    }
    int res = max_edges(N, M, edges);
    cout << (res == -1 ? -1 : to_string(res)) << endl;
    return 0;
}
This code first sorts the edges based on their type. Then it initializes the disjoint-set data structure and for each edge, it checks if the two vertices of the edge belong to the same set. If they don't, it unites them and either Alice or Bob is reduced by 1. If both are present in different sets, then it returns -1 as it's not possible to remove more than one edge between Alice and Bob. Otherwise, it returns the number of edges removed.