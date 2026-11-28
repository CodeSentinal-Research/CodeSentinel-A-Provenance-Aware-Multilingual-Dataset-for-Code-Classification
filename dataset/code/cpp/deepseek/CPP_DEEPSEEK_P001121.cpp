#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> degree(n, 0);
    vector<vector<int>> graph(n, vector<int>());
    queue<int> q;

    for (auto& e : edges) {
        graph[e.first].push_back(e.second);
        graph[e.second].push_back(e.first);
        degree[e.first]++;
        degree[e.second]++;
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    while (n > 2) {
        int size = q.size();
        n -= size;
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();

            for (int& nei : graph[node]) {
                if (--degree[nei] == 1) {
                    q.push(nei);
                }
                graph[node].clear();
            }
        }
    }

    vector<int> roots;
    while (!q.empty()) {
        roots.push_back(q.front());
        q.pop();
    }

    return roots;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = make_pair(a, b);
    }

    vector<int> roots = findMinHeightTrees(n, edges);

    for (int root : roots) {
        cout << root << endl;
    }

    return 0;
}
This code first builds the graph from the input edges. Then it uses a BFS approach to find the root nodes of the minimum height trees. The root nodes are the nodes with degree 1. After finding these roots, it removes the leaves (nodes with degree 1) and continues the process until only two or no nodes left (which is the root of the minimum height tree). The remaining nodes are the roots of the trees.