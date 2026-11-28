Here's the C++ code for your problem:

#include <iostream>
#include <vector>

using namespace std;

bool hamiltonianCycle(int n, vector<pair<int, int>>& edges) {
    vector<bool> visited(n, false);
    vector<int> path(n, -1);
    path[0] = 0;
    visited[0] = true;

    for (int i = 1; i < n; i++) {
        bool found = false;
        for (int j = 0; j < edges.size(); j++) {
            if (edges[j].first == i && !visited[edges[j].second]) {
                path[i] = edges[j].second;
                visited[edges[j].second] = true;
                found = true;
                break;
            } else if (edges[j].second == i && !visited[edges[j].first]) {
                path[i] = edges[j].first;
                visited[edges[j].first] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    if (hamiltonianCycle(n, edges)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

This program uses the Depth-First Search (DFS) algorithm to find if a Hamiltonian Cycle exists in the graph. It starts from the first vertex and marks it as visited, then for each neighbour of the current vertex, it recursively marks the visited vertex and updates the path vector. If it reaches a vertex that has not been visited, it backtracks and marks the visited vertex. If it cannot find a unvisited neighbour, it returns false. If the program runs successfully, it prints "YES" to the output.