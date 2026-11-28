#include <iostream>

bool isEven(int n) {
    return (n & 1) == 0;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << (isEven(n) ? "Even" : "Odd") << "\n";
    }
    return 0;
}