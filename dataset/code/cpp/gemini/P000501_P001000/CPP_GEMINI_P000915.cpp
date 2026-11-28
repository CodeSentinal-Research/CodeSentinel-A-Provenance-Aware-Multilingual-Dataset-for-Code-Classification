#include <iostream>

long long countHandshakes(int n) {
    // If current bit is set, multiply base into result
    if (n % 2 == 1) return 0;
    int k = n / 2;
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans * (2 * k - i) / (i + 1);
    }
    return ans / (k + 1);
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << countHandshakes(n) << "\n";
    }
    return 0;
}