#include <iostream>

long long sumOfNaturalNumbers(long long n) {
    if (n < 0) return 0;
    return (n * (n + 1)) / 2;
}

int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << sumOfNaturalNumbers(n) << "\n";
    }
    return 0;
}