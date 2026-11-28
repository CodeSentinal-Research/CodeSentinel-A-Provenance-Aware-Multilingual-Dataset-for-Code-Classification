#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char dname[] = {'D', 'L', 'R', 'U'};
void backtrack(int n, int r, int c, const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& vis, std::string path, std::vector<std::string>& res) {
    if (r == n - 1 && c == n - 1) {
        res.push_back(path);
        return;
    }
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]) {
            backtrack(n, nr, nc, grid, vis, path + dname[i], res);
        }
    }
    vis[r][c] = false;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> grid(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cin >> grid[i][j];
        }
        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return 0;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
        std::vector<std::string> res;
        backtrack(n, 0, 0, grid, vis, "", res);
        std::sort(res.begin(), res.end());
        for (const auto& p : res) std::cout << p << std::endl;
    }
    return 0;
}