#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int node;
    int weight;
};

const int MAX = 100005;
vector<Edge> graph[MAX];
bool visited[MAX];

int prim(int N) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    int total_weight = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        for (auto &edge : graph[i]) {
            pq.push(edge);
        }
        while (!pq.empty()) {
            Edge top = pq.top();
            pq.pop();
            if (!visited[top.node]) {
                visited[top.node] = true;
                total_weight += top.weight;
                break;
            }
        }
    }
    return total_weight;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << prim(N) << '\n';
    return 0;
}