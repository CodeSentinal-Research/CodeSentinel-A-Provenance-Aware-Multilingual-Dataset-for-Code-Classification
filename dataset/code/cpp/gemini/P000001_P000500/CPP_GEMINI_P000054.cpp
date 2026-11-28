#include <iostream>
int main() {
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c > 'A') std::cout << " ";
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}