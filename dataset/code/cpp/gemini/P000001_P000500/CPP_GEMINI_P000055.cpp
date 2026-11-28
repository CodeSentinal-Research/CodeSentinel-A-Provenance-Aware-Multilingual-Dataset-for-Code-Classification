#include <iostream>
int main() {
    for (char c = 'Z'; c >= 'A'; c--) {
        if (c < 'Z') std::cout << " ";
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}