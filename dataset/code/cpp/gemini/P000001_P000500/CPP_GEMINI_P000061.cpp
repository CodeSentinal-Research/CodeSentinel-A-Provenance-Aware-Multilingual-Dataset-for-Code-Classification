#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::string s;
    if (std::cin >> s) {
        int count = 0;
        for (char c : s) if (std::isdigit(c) && (c - '0') % 2 != 0) count++;
        std::cout << count << std::endl;
    }
    return 0;
}