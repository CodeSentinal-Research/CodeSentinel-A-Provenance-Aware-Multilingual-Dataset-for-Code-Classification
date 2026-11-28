#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findAllPaths(vector<vector<int>>& adj, int current, int target, vector<int>& path, vector<vector<int>>& result) {
    path.push_back(current);
    if (current == target) {
        result.push_back(path);
    } else {
        for (int neighbor : adj[current]) {
            findAllPaths(adj, neighbor, target, path, result);
        }
    }
    path.pop_back();
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<vector<int>> result;
    vector<int> path;
    findAllPaths(adj, 0, V - 1, path, result);
    
    for (const auto& p : result) {
        for (size_t i = 0; i < p.size(); ++i) {
            if (i > 0) cout << " ";
            cout << p[i];
        }
        cout << endl;
    }
    return 0;
}
