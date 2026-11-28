#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    vector<int> degree(V, 0);
    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    bool isEulerian = false;
    int oddDegree = 0;
    for(int i = 0; i < V; i++) {
        if(degree[i] % 2 != 0) {
            if(oddDegree == 0) {
                oddDegree = 1;
            } else {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    if(oddDegree == 0) {
        isEulerian = true;
    }

    if(isEulerian) {
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(degree[i] % 2 != 0) {
                q.push(i);
                break;
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int v : graph[u]) {
                if(--degree[v] % 2 != 0) {
                    q.push(v);
                }
            }
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}