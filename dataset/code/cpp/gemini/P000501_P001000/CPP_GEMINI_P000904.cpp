#include <iostream>

long long modAdd(long long a, long long b, long long m) {
    return ((a % m) + (b % m)) % m;
}

int main() {
    long long a, b, m;
    if (std::cin >> a >> b >> m) {
        std::cout << modAdd(a, b, m) << "\n";
    }
    return 0;
}