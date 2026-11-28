#include <iostream>
#include <vector>
#include <queue>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> rooms(n);
        for (int i = 0; i < n; i++) {
            int k; std::cin >> k;
            rooms[i].resize(k);
            for (int j = 0; j < k; j++) std::cin >> rooms[i][j];
        }
        std::vector<bool> vis(n, false);
        std::queue<int> q;
        q.push(0);
        vis[0] = true;
        int count = 1;
        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int key : rooms[r]) {
                if (!vis[key]) {
                    vis[key] = true;
                    count++;
                    q.push(key);
                }
            }
        }
        std::cout << (count == n ? "true" : "false") << std::endl;
    }
    return 0;
}