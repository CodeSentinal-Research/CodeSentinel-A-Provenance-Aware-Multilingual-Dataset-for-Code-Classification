#include <iostream>
#include <vector>

int dfs(const std::vector<std::vector<int>>& grid, int r, int c, int cur, int target, int m, int n) {
    if (r >= m || c >= n) return 0;
    cur += grid[r][c];
    if (r == m - 1 && c == n - 1) return cur == target ? 1 : 0;
    return dfs(grid, r + 1, c, cur, target, m, n) + dfs(grid, r, c + 1, cur, target, m, n);
}

int main() {
    int m, n, target;
    if (std::cin >> m >> n >> target) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> grid[i][j];
        }
        std::cout << dfs(grid, 0, 0, 0, target, m, n) << "\n";
    }
    return 0;
}