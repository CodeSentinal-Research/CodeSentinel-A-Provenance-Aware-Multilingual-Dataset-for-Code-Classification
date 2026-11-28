#include <iostream>
#include <string>
int main() {
    std::string s;
    if (std::cin >> s) {
        if (s == "-1") std::cout << 0 << std::endl;
        else std::cout << s << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}