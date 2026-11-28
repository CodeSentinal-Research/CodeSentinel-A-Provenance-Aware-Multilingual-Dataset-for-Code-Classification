#include <iostream>
#include <string>
#include <algorithm>
void var_jump_paths(int n, int m, int r, int c, std::string path) {
    if (r == n && c == m) {
        std::cout << path << std::endl;
        return;
    }
    for (int k = 1; k <= m - c; k++) {
        var_jump_paths(n, m, r, c + k, path + "H" + std::to_string(k));
    }
    for (int k = 1; k <= n - r; k++) {
        var_jump_paths(n, m, r + k, c, path + "V" + std::to_string(k));
    }
    for (int k = 1; k <= std::min(n - r, m - c); k++) {
        var_jump_paths(n, m, r + k, c + k, path + "D" + std::to_string(k));
    }
}
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        var_jump_paths(n, m, 1, 1, "");
    }
    return 0;
}