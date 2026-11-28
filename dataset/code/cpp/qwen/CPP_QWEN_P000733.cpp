#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) return true;
    
    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int V, E, M;
    cin >> V >> E >> M;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    vector<int> color(V, 0);
    cout << (graphColoringUtil(graph, M, color, 0) ? "true" : "false") << endl;
    return 0;
}
