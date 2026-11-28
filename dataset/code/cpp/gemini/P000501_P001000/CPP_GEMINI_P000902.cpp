#include <iostream>

long long countDivisibleInRange(long long l, long long r, long long k) {
    return (r / k) - ((l - 1) / k);
}

int main() {
    long long l, r, k;
    if (std::cin >> l >> r >> k) {
        std::cout << countDivisibleInRange(l, r, k) << "\n";
    }
    return 0;
}