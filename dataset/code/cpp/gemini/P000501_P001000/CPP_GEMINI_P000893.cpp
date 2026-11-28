#include <iostream>
#include <vector>

std::vector<long long> distinctPrimeFactors(long long n) {
    std::vector<long long> factors;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            factors.push_back(d);
            while (n % d == 0) n /= d;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

int main() {
    long long n;
    if (std::cin >> n) {
        auto res = distinctPrimeFactors(n);
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}