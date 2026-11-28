#include <iostream>
#include <numeric>
int main() {
    long long a, b, c;
    if (std::cin >> a >> b >> c) {
        long long lcm_ab = std::lcm(a, b);
        std::cout << std::lcm(lcm_ab, c) << std::endl;
    }
    return 0;
}