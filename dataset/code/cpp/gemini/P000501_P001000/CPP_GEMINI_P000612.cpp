#include <iostream>
#include <vector>
#include <numeric>
int gcd(int a, int b) { return std::gcd(a, b); }
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        for (int i = 0; i < n; i++) {
            std::cout << vals[i] << " ";
            if (i + 1 < n) std::cout << gcd(vals[i], vals[i + 1]) << (i + 1 == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}