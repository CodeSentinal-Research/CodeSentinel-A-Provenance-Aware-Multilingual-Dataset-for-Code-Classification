#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> phi(n + 1);
        std::iota(phi.begin(), phi.end(), 0);
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            std::cout << phi[i] << (i == n ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}