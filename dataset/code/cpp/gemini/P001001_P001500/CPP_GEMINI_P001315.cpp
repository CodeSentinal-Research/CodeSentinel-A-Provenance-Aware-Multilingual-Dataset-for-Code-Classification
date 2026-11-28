#include <iostream>
#include <vector>
#include <string>

int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char dChars[] = {'D', 'L', 'R', 'U'};

void backtrack(int r, int c, int n, const std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visited, std::string& path, std::vector<std::string>& res) {
    if (r == n - 1 && c == n - 1) {
        res.push_back(path);
        return;
    }

    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && maze[nr][nc] == 1) {
            path.push_back(dChars[i]);
            backtrack(nr, nc, n, maze, visited, path, res);
            path.pop_back();
        }
    }
    visited[r][c] = false;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> maze(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cin >> maze[i][j];
        }

        std::vector<std::string> res;
        if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
            std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
            std::string path = "";
            backtrack(0, 0, n, maze, visited, path, res);
        }

        if (res.empty()) {
            std::cout << "-1\n";
        } else {
            for (size_t i = 0; i < res.size(); i++) {
                std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}