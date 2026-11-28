#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;
    if (std::cin >> a >> b) {
        if (a == b) std::cout << -1 << std::endl;
        else std::cout << std::max(a.length(), b.length()) << std::endl;
    }
    return 0;
}