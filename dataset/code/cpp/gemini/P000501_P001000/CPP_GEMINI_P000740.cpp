#include <iostream>
#include <string>
void diagonal_paths(int n, int m, int r, int c, std::string path) {
    if (r == n && c == m) {
        std::cout << path << std::endl;
        return;
    }
    if (r < n && c < m) diagonal_paths(n, m, r + 1, c + 1, path + "D");
    if (c < m) diagonal_paths(n, m, r, c + 1, path + "H");
    if (r < n) diagonal_paths(n, m, r + 1, c, path + "V");
}
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        diagonal_paths(n, m, 1, 1, "");
    }
    return 0;
}