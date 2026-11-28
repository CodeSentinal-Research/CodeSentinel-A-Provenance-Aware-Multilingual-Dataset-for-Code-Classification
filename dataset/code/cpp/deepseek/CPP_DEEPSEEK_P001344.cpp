Sure, here's the code for that problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void DFSVisit(int v, vector<bool>& visited, vector<int>& path, vector<vector<int>>& result) {
        visited[v] = true;
        path.push_back(v);
        if (v == V - 1) {
            result.push_back(path);
        } else {
            for (int i : adj[v]) {
                if (!visited[i]) {
                    DFSVisit(i, visited, path, result);
                }
            }
        }
        path.pop_back();
        visited[v] = false;
    }
public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void generateAllPaths(int s) {
        vector<bool> visited(V, false);
        vector<int> path;
        vector<vector<int>> result;
        DFSVisit(s, visited, path, result);
        for (auto& res : result) {
            for (int i : res) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }
    g.generateAllPaths(0);
    return 0;
}

This code uses a DFS approach to find all the possible paths from source to target in the given DAG. The `DFSVisit` function is a helper function that does the actual DFS. It starts from the source vertex and recursively visits all the vertices reachable from the current vertex. When it reaches the target vertex, it adds the current path to the result.

The main function reads the number of vertices and edges, and constructs a graph from these information. It then calls `generateAllPaths` to print all the paths.