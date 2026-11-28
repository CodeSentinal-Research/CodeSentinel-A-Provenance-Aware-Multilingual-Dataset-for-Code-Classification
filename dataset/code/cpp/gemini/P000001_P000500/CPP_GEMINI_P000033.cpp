#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        long long total = 0;
        for (int i = 1; i <= n; i++) if (n % i == 0) total += i;
        std::cout << total << std::endl;
    }
    return 0;
}