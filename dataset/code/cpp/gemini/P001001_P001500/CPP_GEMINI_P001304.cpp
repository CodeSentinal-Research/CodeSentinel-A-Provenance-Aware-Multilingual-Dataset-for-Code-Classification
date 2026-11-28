#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<int> x(m - 1), y(n - 1);
        for (int i = 0; i < m - 1; i++) std::cin >> x[i];
        for (int j = 0; j < n - 1; j++) std::cin >> y[j];

        std::sort(x.rbegin(), x.rend());
        std::sort(y.rbegin(), y.rend());

        long long hPieces = 1, vPieces = 1, totalCost = 0;
        size_t i = 0, j = 0;

        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                totalCost += (long long)x[i] * vPieces;
                hPieces++;
                i++;
            } else {
                totalCost += (long long)y[j] * hPieces;
                vPieces++;
                j++;
            }
        }
        while (i < x.size()) {
            totalCost += (long long)x[i] * vPieces;
            i++;
        }
        while (j < y.size()) {
            totalCost += (long long)y[j] * hPieces;
            j++;
        }

        std::cout << totalCost << "\n";
    }
    return 0;
}