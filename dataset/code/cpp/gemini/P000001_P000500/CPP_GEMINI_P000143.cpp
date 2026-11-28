#include <iostream>
#include <vector>
int main() {
    int r, c;
    if (std::cin >> r >> c) {
        std::vector<std::vector<int>> grid(r, std::vector<int>(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                std::cin >> grid[i][j];
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                if (i > 0) std::cout << " ";
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}