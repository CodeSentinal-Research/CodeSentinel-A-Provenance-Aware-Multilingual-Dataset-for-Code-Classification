#include <iostream>
#include <string>
int main() {
    std::string b;
    if (std::cin >> b) {
        std::cout << std::stoi(b, nullptr, 2) << std::endl;
    }
    return 0;
}