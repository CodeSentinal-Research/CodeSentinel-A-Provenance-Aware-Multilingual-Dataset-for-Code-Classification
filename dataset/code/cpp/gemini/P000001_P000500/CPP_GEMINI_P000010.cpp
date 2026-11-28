#include <iostream>
#include <algorithm>

int main() {
    int a, b;
    if (std::cin >> a >> b) {
        std::cout << std::min(a, b) << std::endl;
    }
    return 0;
}