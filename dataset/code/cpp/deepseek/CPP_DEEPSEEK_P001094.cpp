#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(int start, vector<vector<int>>& graph, vector<int>& matchR, vector<bool>& visited) {
    queue<int> q;
    q.push(start);

    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i];

            if (matchR[u] == -1 || visited[matchR[u]])
                continue;

            visited[matchR[u]] = true;
            q.push(matchR[u]);
        }
    }

    return visited[start] = true;
}

int maxMatching(vector<vector<int>>& graph, int start) {
    int N = graph.size();
    vector<int> matchR(N, -1);
    int matching = 0;

    for (int i = 0; i < N; i++) {
        if (BFS(i, graph, matchR, visited))
            matching++;
    }

    return matching;
}

int main() {
    int L, R, M;
    cin >> L >> R >> M;

    vector<vector<int>> graph(L + R);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b + L);
    }

    int matching = maxMatching(graph, 0);

    cout << matching << endl;

    return 0;
}
This C++ solution uses the BFS (Breadth-First Search) algorithm to find the maximum matching in the bipartite graph. The BFS algorithm is used to find whether there is a path from a node to the source node (in this case, the left partition node). If a path is found, it means that the corresponding right partition node is unmatched, so the matching count is increased by 1. The matching count is then printed as the output.