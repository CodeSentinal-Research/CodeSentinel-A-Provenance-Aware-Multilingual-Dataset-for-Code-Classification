#include <iostream>
#include <vector>
#include <queue>

int main() {
    int moves;
    if (std::cin >> moves) {
        std::vector<int> board(31, -1);
        for (int i = 0; i < moves; i++) {
            int u, v;
            std::cin >> u >> v;
            board[u] = v;
        }
        std::vector<bool> vis(31, false);
        std::queue<std::pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;
        int ans = -1;

        while (!q.empty()) {
            auto [pos, steps] = q.front();
            q.pop();
            if (pos == 30) {
                ans = steps;
                break;
            }
            for (int d = 1; d <= 6; d++) {
                int next = pos + d;
                if (next <= 30) {
                    if (board[next] != -1) next = board[next];
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push({next, steps + 1});
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}