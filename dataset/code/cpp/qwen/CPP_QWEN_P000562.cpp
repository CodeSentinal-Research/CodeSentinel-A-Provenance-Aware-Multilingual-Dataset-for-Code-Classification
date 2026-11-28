#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> rooms(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        rooms[i].resize(k);
        for (int j = 0; j < k; j++) cin >> rooms[i][j];
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int room = q.front(); q.pop();
        for (int key : rooms[room]) {
            if (!visited[key]) {
                visited[key] = true;
                q.push(key);
            }
        }
    }
    for (bool v : visited) {
        if (!v) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}
