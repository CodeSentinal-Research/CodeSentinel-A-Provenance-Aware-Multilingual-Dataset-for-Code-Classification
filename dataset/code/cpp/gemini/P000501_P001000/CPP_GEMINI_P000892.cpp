#include <iostream>
#include <vector>

std::vector<long long> primeFactors(long long n) {
    std::vector<long long> factors;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

int main() {
    long long n;
    if (std::cin >> n) {
        auto res = primeFactors(n);
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}