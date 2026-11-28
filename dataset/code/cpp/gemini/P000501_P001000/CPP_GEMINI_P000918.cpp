#include <iostream>

long long circularArrangements(int n) {
    if (n <= 1) return 1;
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << circularArrangements(n) << "\n";
    }
    return 0;
}