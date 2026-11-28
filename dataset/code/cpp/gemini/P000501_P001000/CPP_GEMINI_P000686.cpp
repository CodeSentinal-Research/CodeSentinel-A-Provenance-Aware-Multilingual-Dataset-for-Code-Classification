#include <iostream>
#include <string>
std::string rev_str(const std::string& s) {
    if (s.length() <= 1) return s;
    return s.back() + rev_str(s.substr(0, s.length() - 1));
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << rev_str(s) << std::endl;
    }
    return 0;
}