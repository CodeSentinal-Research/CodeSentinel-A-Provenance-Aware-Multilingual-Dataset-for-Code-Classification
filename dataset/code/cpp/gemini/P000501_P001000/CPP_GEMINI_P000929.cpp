#include <iostream>
#include <vector>

int main() {
    int r, c;
    if (std::cin >> r >> c && r > 0 && c > 0) {
        std::vector<std::vector<int>> a(r, std::vector<int>(c));
        std::vector<std::vector<int>> b(r, std::vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) std::cin >> a[i][j];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) std::cin >> b[i][j];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << a[i][j] + b[i][j] << (j == c - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}