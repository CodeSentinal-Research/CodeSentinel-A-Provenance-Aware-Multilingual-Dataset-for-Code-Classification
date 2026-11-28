#include <iostream>
#include <string>

int main() {
    std::string s;
    char c;
    if (std::cin >> s >> c) {
        size_t pos = s.find(c);
        if (pos != std::string::npos) std::cout << pos << std::endl;
        else std::cout << -1 << std::endl;
    }
    return 0;
}