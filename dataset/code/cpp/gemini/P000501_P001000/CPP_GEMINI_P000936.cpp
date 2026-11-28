#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<std::vector<int>> mat(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cin >> mat[i][j];
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}