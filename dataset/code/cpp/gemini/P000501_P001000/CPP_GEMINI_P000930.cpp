#include <iostream>
#include <vector>

int main() {
    int r1, c1;
    if (std::cin >> r1 >> c1) {
        std::vector<std::vector<int>> a(r1, std::vector<int>(c1));
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) std::cin >> a[i][j];
        }
        int r2, c2;
        if (std::cin >> r2 >> c2) {
            std::vector<std::vector<int>> b(r2, std::vector<int>(c2));
            for (int i = 0; i < r2; i++) {
                for (int j = 0; j < c2; j++) std::cin >> b[i][j];
            }
            std::vector<std::vector<int>> res(r1, std::vector<int>(c2, 0));
            for (int i = 0; i < r1; i++) {
                for (int k = 0; k < c1; k++) {
                    for (int j = 0; j < c2; j++) {
                        res[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                    std::cout << res[i][j] << (j == c2 - 1 ? "" : " ");
                }
                std::cout << "\n";
            }
        }
    }
    return 0;
}