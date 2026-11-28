#include <iostream>

long long modSub(long long a, long long b, long long m) {
    return ((a % m) - (b % m) + m) % m;
}

int main() {
    long long a, b, m;
    if (std::cin >> a >> b >> m) {
        std::cout << modSub(a, b, m) << "\n";
    }
    return 0;
}