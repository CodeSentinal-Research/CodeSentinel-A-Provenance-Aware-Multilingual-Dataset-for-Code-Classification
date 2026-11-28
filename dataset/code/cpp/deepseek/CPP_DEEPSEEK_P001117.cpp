#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_VERTICES = 10000;

vector<int> graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for(int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];

            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int v, e;
        cin >> v >> e;

        for(int j = 0; j < e; j++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        bfs(i);
        cout << endl;

        for(int j = 0; j < n; j++) {
            visited[j] = 0;
        }
    }

    return 0;
}