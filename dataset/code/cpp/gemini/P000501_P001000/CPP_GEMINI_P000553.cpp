#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> board(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cin >> board[i][j];
        }
        std::vector<int> arr(n * n + 1, -1);
        int cur = 1;
        for (int r = n - 1; r >= 0; r--) {
            if ((n - 1 - r) % 2 == 0) {
                for (int c = 0; c < n; c++) arr[cur++] = board[r][c];
            } else {
                for (int c = n - 1; c >= 0; c--) arr[cur++] = board[r][c];
            }
        }
        std::queue<std::pair<int, int>> q;
        std::vector<bool> vis(n * n + 1, false);
        q.push({1, 0});
        vis[1] = true;
        int ans = -1;
        while (!q.empty()) {
            auto [pos, moves] = q.front(); q.pop();
            if (pos == n * n) { ans = moves; break; }
            for (int step = 1; step <= 6; step++) {
                int nxt = pos + step;
                if (nxt <= n * n) {
                    int dest = (arr[nxt] != -1) ? arr[nxt] : nxt;
                    if (!vis[dest]) {
                        vis[dest] = true;
                        q.push({dest, moves + 1});
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}