#include <iostream>
#include <vector>
#include <string>
bool can_place_h(int n, const std::vector<std::string>& grid, int r, int c, const std::string& w) {
    if (c + (int)w.length() > n) return false;
    for (size_t i = 0; i < w.length(); i++) {
        if (grid[r][c + i] != '-' && grid[r][c + i] != w[i]) return false;
    }
    return true;
}
std::vector<std::pair<int, int>> place_h(std::vector<std::string>& grid, int r, int c, const std::string& w) {
    std::vector<std::pair<int, int>> placed;
    for (size_t i = 0; i < w.length(); i++) {
        if (grid[r][c + i] == '-') {
            grid[r][c + i] = w[i];
            placed.push_back({r, c + i});
        }
    }
    return placed;
}
bool can_place_v(int n, const std::vector<std::string>& grid, int r, int c, const std::string& w) {
    if (r + (int)w.length() > n) return false;
    for (size_t i = 0; i < w.length(); i++) {
        if (grid[r + i][c] != '-' && grid[r + i][c] != w[i]) return false;
    }
    return true;
}
std::vector<std::pair<int, int>> place_v(std::vector<std::string>& grid, int r, int c, const std::string& w) {
    std::vector<std::pair<int, int>> placed;
    for (size_t i = 0; i < w.length(); i++) {
        if (grid[r + i][c] == '-') {
            grid[r + i][c] = w[i];
            placed.push_back({r + i, c});
        }
    }
    return placed;
}
void unplace(std::vector<std::string>& grid, const std::vector<std::pair<int, int>>& placed) {
    for (auto p : placed) grid[p.first][p.second] = '-';
}
bool backtrack(int n, std::vector<std::string>& grid, const std::vector<std::string>& words, int idx) {
    if (idx == (int)words.size()) return true;
    const std::string& w = words[idx];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (can_place_h(n, grid, r, c, w)) {
                auto placed = place_h(grid, r, c, w);
                if (backtrack(n, grid, words, idx + 1)) return true;
                unplace(grid, placed);
            }
            if (can_place_v(n, grid, r, c, w)) {
                auto placed = place_v(grid, r, c, w);
                if (backtrack(n, grid, words, idx + 1)) return true;
                unplace(grid, placed);
            }
        }
    }
    return false;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> grid(n);
        for (int i = 0; i < n; i++) std::cin >> grid[i];
        int w_cnt; std::cin >> w_cnt;
        std::vector<std::string> words(w_cnt);
        for (int i = 0; i < w_cnt; i++) std::cin >> words[i];
        backtrack(n, grid, words, 0);
        for (int i = 0; i < n; i++) std::cout << grid[i] << std::endl;
    }
    return 0;
}