#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countVertices(int N, int M, int S, int K, vector<pair<int, int>> edges) {
    vector<int> dist(N, -1);
    dist[S] = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<int> q;
    q.push(S);
    visited[S][S] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : edges) {
            int adjNode = it.first;
            if (!visited[node][adjNode] && dist[node] != dist[adjNode] + 1) {
                visited[node][adjNode] = true;
                dist[adjNode] = dist[node] + 1;
                q.push(adjNode);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] == K) {
            count++;
        }
    }

    return count;
}

int main() {
    int N, M, S, K;
    cin >> N >> M >> S >> K;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(v, u);
    }

    int result = countVertices(N, M, S, K, edges);
    cout << result << "\n";

    return 0;
}