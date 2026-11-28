#include <iostream>
#include <vector>
#include <numeric>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int res = arr[0];
        for (int i = 1; i < n; i++) res = gcd(res, arr[i]);
        std::cout << res << "\n";
    }
    return 0;
}