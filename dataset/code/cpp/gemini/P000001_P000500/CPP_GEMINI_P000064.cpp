#include <iostream>
#include <numeric>
int main() {
    long long a, b;
    if (std::cin >> a >> b) std::cout << std::gcd(a, b) << std::endl;
    return 0;
}