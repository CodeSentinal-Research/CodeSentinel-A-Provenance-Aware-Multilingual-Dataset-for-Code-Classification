#include <iostream>
#include <vector>
#include <string>
int main() {
    std::string s;
    if (std::cin >> s) {
        if (s == "-1") std::cout << "false\n";
        else std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    return 0;
}