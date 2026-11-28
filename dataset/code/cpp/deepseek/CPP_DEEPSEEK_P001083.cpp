Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCycleUtil(int v, vector<int> graph[], bool visited[], bool *recStk) {
    visited[v] = true;
    recStk[v] = true;
    
    for (int u : graph[v]) {
        if (!visited[u]) {
            if (isCycleUtil(u, graph, visited, recStk)) {
                return true;
            } else if (recStk[u]) {
                return true;
            }
        } else if (recStk[u]) {
            return true;
        }
    }
    
    recStk[v] = false;
    return false;
}

bool isCycle(int v, vector<int> graph[], int N) {
    bool visited[N] = {false};
    bool recStk[N] = {false};
    
    if (isCycleUtil(v, graph, visited, recStk)) {
        return true;
    }
    
    for (int i = 0; i < N; i++) {
        if (visited[i] && graph[i].size() > 0) {
            return false;
        }
    }
    
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> graph[N];
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if (isCycle(0, graph, N)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    
    return 0;
}

This code uses depth-first search (DFS) to check if there's a cycle in the graph. A cycle occurs when we find a vertex that has been visited, but not all of its neighbours have been visited. In the case of a Hamiltonian path, we don't need to check all the vertices because we can always go back to the source and start another path from there.