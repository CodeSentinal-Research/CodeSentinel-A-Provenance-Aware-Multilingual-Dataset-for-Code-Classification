#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
        int reachable = 0;
        for (auto& edge : graph[i]) {
            if (edge.first <= T) {
                reachable++;
            } else {
                break;
            }
        }
        if (reachable == N - i - 1) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}