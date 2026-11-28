#include <iostream>
#include <string>

int main() {
    std::string s;
    if (std::cin >> s) {
        long long res = 0;
        for (char c : s) {
            if (c == '0' || c == '1') {
                res = (res << 1) | (c - '0');
            }
        }
        std::cout << res << "\n";
    }
    return 0;
}