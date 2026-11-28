#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100005];
bool vis[100005];

bool dfs(int node) {
    vis[node] = true;

    for (int child : graph[node]) {
        if (!vis[child]) {
            if (dfs(child)) {
                return true;
            }
        } else if (vis[child]) {
            return true;
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
    }

    for (int i = 1; i <= N; i++) {
        if (dfs(i)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
This code works by performing a depth-first search (DFS) from each node to check if there is any cycle. The `dfs` function uses a boolean array `vis` to mark nodes as visited. If a node is already visited, it means that a cycle has been detected. If a node is not visited but there is a child node that has been visited (a directed edge), then a cycle has been detected. If a node is not visited and there is no child node that has been visited (an unvisited node), then no cycle has been detected.