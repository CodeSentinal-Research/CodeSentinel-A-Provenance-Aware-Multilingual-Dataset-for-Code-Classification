#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, V;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> V;
    sort(graph[V].begin(), graph[V].end());
    for (int neighbor : graph[V]) {
        cout << neighbor << " ";
    }
    return 0;
}