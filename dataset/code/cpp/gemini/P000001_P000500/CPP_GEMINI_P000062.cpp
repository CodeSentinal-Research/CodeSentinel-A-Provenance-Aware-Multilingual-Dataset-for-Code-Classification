#include <iostream>
int fact(int n) { int f = 1; for (int i = 2; i <= n; i++) f *= i; return f; }
int main() {
    int n;
    if (std::cin >> n) {
        int temp = n, sum = 0;
        while (temp > 0) { sum += fact(temp % 10); temp /= 10; }
        std::cout << (sum == n ? "Strong" : "Not Strong") << std::endl;
    }
    return 0;
}