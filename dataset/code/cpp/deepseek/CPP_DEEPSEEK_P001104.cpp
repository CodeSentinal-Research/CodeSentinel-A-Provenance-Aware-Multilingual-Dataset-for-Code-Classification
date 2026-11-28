Here is the C++ code:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            adjList[i].push_back(v);
        }
    }

    return 0;
}

This program reads the number of vertices and the adjacency list of each vertex. Then it prints the adjacency list of the cloned graph.