#include <iostream>
#include <vector>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Computes the Least Common Multiple (LCM).
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        long long res = arr[0];
        for (int i = 1; i < n; i++) res = lcm(res, arr[i]);
        std::cout << res << "\n";
    }
    return 0;
}