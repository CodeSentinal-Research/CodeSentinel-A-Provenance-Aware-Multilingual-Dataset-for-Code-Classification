#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionSet(int node1, int node2) {
    node1 = findParent(node1);
    node2 = findParent(node2);

    if (node1 == node2)
        return false;

    parent[node2] = node1;
    return true;
}

bool areIsomorphic(int N, int M1, int M2) {
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= M1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        if (!unionSet(node1, node2))
            return false;
    }

    for (int i = 1; i <= M2; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        if (findParent(node1) == findParent(node2))
            return false;
    }

    return true;
}

int main() {
    int N, M1, M2;
    cin >> N >> M1 >> M2;
    cout << (areIsomorphic(N, M1, M2) ? "YES" : "NO") << '\n';
    return 0;
}
This program reads the number of vertices and edges for the two graphs, and then calls the `areIsomorphic` function. It uses Union-Find data structure to check if the two graphs are isomorphic or not. The `unionSet` function is used to merge two nodes, while the `findParent` function is used to find the parent of a node. If the two graphs are isomorphic, they will have the same parent after merging all the nodes.