#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            sum += x;
        }
        std::cout << sum << "\n";
    }
    return 0;
}