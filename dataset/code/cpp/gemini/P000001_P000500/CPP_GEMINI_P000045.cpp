#include <iostream>
int main() {
    long long n;
    if (std::cin >> n) {
        long long total = n * (n + 1) * (2 * n + 1) / 6;
        std::cout << total << std::endl;
    }
    return 0;
}