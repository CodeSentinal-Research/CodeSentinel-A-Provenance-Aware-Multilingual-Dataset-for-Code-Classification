#include <iostream>
int main() {
    double a, b, c;
    if (std::cin >> a >> b >> c) {
        bool valid = (a + b > c) && (a + c > b) && (b + c > a);
        std::cout << (valid ? "Valid" : "Invalid") << std::endl;
    }
    return 0;
}