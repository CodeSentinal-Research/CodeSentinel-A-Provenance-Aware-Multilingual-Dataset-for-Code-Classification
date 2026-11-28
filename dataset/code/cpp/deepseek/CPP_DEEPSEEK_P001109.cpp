#include <iostream>
#include <vector>

using namespace std;

bool isValid(int vertex, int color, vector<int>& colors, vector<vector<bool>>& graph) {
    for(int i = 0; i < graph.size(); i++) {
        if(graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

void solve(int vertex, int color, vector<int>& colors, vector<vector<bool>>& graph) {
    for(int i = 0; i < graph.size(); i++) {
        if(graph[vertex][i]) {
            if(colors[i] == color) {
                colors[i] = 0;
                solve(i, 1 - color, colors, graph);
                return;
            } else if(!isValid(i, color, colors, graph)) {
                return;
            }
        }
    }
    colors[vertex] = color;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> graph(N, vector<bool>(N));
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u][v] = graph[v][u] = true;
    }
    vector<int> colors(N);
    for(int i = 0; i < N; i++) {
        int c;
        cin >> c;
        c--;
        solve(i, c, colors, graph);
    }
    cout << "VALID";
    return 0;
}