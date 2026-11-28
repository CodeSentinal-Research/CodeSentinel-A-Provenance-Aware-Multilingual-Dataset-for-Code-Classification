#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPossible(int n, vector<pair<int, int>> &prerequisites) {
    vector<list<int>> adjList(n + 1);
    vector<int> indegree(n + 1, 0);

    for (auto &pre : prerequisites) {
        adjList[pre.second].push_back(pre.first);
        indegree[pre.first]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto &neighbor : adjList[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> prerequisites;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        prerequisites.push_back({u, v});
    }

    cout << (isPossible(n, prerequisites) ? "YES" : "NO") << endl;

    return 0;
}