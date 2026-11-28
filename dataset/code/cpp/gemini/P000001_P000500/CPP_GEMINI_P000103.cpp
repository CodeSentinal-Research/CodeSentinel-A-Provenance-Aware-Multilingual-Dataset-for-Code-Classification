#include <iostream>
#include <vector>
#include <numeric>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long val;
            std::cin >> val;
            total += val;
        }
        std::cout << total << std::endl;
    }
    return 0;
}