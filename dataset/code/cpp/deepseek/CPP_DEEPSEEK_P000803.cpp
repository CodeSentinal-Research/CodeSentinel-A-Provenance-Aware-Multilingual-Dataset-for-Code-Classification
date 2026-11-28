#include <iostream>
#include <vector>

int countSubmatrices(int N, int M, std::vector<std::vector<int>> &grid, int target) {
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> grid(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> grid[i][j];
        }
    }
    int target;
    std::cin >> target;
    std::cout << countSubmatrices(N, M, grid, target);
    return 0;
}