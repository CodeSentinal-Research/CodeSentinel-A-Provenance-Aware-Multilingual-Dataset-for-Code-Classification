#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100005];
bool visited[100005];

bool dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (!visited[child]) {
            if (dfs(child)) {
                cout << child + 1 << " ";
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        if (graph[i].size() % 2 != 0) {
            if (dfs(i)) {
                cout << i + 1;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
This C++ code will solve the problem. The graph is represented as an adjacency list. The dfs function is used to detect if the graph contains a Eulerian circuit. The dfs function works by visiting each node and then for each node, it visits all its children. If it finds a child that hasn't been visited, it recursively calls dfs on that child. If it can't find a child that hasn't been visited, it returns false. If it can't find a such a child, it returns true.