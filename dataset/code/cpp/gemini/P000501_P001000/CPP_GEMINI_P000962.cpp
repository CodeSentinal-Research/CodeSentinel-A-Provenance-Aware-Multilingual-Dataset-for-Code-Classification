#include <iostream>

long long frobeniusNumber(long long a, long long b) {
    return a * b - a - b;
}

int main() {
    long long a, b;
    if (std::cin >> a >> b) {
        std::cout << frobeniusNumber(a, b) << "\n";
    }
    return 0;
}