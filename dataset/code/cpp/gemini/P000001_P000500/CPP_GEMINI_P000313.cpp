#include <iostream>
#include <string>
#include <regex>

bool isValidNumber(const std::string& s) {
    std::regex pattern(R"(^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$)");
    return std::regex_match(s, pattern);
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (isValidNumber(s) ? "Valid" : "Invalid") << std::endl;
    }
    return 0;
}