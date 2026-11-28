#include <iostream>
int main() {
    long long a, b;
    if (std::cin >> a >> b) {
        std::cout << (a % b == 0 ? "Divisible" : "Not Divisible") << std::endl;
    }
    return 0;
}