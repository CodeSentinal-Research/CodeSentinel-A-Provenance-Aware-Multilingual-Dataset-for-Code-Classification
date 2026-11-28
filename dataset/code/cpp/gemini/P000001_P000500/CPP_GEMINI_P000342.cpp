#include <iostream>
#include <string>

int main() {
    std::string s;
    if (std::cin >> s) {
        for (size_t i = 1; i < s.length(); i += 2) {
            s[i] = s[i - 1] + (s[i] - '0');
        }
        std::cout << s << std::endl;
    }
    return 0;
}