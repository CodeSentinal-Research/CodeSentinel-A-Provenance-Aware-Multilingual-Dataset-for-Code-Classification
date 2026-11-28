#include <iostream>
long long gcd_rec(long long a, long long b) {
    if (b == 0) return a;
    return gcd_rec(b, a % b);
}
int main() {
    long long a, b;
    if (std::cin >> a >> b) {
        std::cout << gcd_rec(a, b) << std::endl;
    }
    return 0;
}