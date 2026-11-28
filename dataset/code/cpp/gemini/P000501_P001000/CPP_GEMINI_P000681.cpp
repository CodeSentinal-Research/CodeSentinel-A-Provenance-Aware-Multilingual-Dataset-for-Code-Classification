#include <iostream>
long long sum_rec(int n) {
    if (n <= 0) return 0;
    return n + sum_rec(n - 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::cout << sum_rec(n) << std::endl;
    }
    return 0;
}