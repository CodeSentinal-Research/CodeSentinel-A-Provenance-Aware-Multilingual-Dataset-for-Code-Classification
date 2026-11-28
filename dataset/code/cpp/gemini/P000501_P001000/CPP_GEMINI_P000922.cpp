#include <iostream>
#include <string>
#include <cmath>

long long sumDigitsUpTo(long long n) {
    if (n <= 0) return 0;
    std::string s = std::to_string(n);
    int d = s.length();
    if (d == 1) return n * (n + 1) / 2;
    long long first = s[0] - '0';
    long long rem = std::stoll(s.substr(1).empty() ? "0" : s.substr(1));
    long long p = (long long)std::pow(10, d - 1);

    long long ans = first * 45 * (d - 1) * (p / 10);
    ans += (first * (first - 1) / 2) * p;
    ans += first * (rem + 1);
    ans += sumDigitsUpTo(rem);
    return ans;
}

int main() {
    long long l, r;
    if (std::cin >> l >> r) {
        std::cout << sumDigitsUpTo(r) - sumDigitsUpTo(l - 1) << "\n";
    }
    return 0;
}