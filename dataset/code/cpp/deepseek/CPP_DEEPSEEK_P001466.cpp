#include <iostream>
#include <algorithm>
#include <cctype>

int main() {
    std::string str;
    std::getline(std::cin, str);

    str.erase(std::remove_if(str.begin(), str.end(),
        [](char c) { return !std::isalnum(std::tolower(c)); }), str.end());

    std::string reversed(str);
    std::reverse(reversed.begin(), reversed.end());

    if (str == reversed)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}