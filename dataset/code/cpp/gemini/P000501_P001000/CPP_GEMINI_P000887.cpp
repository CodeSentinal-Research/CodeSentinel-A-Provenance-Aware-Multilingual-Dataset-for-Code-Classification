#include <iostream>

bool isNeon(int n) {
    long long sq = 1LL * n * n;
    long long sum = 0;
    while (sq > 0) {
        sum += sq % 10;
        sq /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << (isNeon(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}