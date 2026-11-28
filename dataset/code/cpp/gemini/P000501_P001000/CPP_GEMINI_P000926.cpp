#include <iostream>
#include <iomanip>

int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << std::oct << n << " " << std::hex << std::uppercase << n << "\n";
    }
    return 0;
}