#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<std::vector<int>> grid(n, std::vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                std::cin >> grid[i][j];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) std::cout << " ";
                std::cout << grid[n - 1 - j][i];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}