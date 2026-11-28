#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int start, vector<vector<int>> &graph, vector<int> &color) {
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int i = 0; i < graph[current].size(); i++) {
            int neighbour = graph[current][i];
            if(color[neighbour] == -1) {
                q.push(neighbour);
                color[neighbour] = 1 - color[current];
            } else if(color[neighbour] == color[current]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph, int V) {
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            if(!bfs(i, graph, color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(isBipartite(graph, V)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}