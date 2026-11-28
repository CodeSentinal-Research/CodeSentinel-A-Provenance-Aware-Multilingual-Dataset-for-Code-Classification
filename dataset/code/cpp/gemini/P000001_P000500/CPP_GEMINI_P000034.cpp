#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        if (n <= 1) { std::cout << "Not Perfect" << std::endl; return 0; }
        int sum = 0;
        for (int i = 1; i < n; i++) if (n % i == 0) sum += i;
        std::cout << (sum == n ? "Perfect" : "Not Perfect") << std::endl;
    }
    return 0;
}