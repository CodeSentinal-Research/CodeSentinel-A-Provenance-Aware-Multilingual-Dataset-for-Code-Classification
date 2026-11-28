#include <iostream>
long long climb_stairs(int n) {
    if (n <= 1) return 1;
    long long a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b; a = b; b = c;
    }
    return b;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::cout << climb_stairs(n) << std::endl;
    }
    return 0;
}