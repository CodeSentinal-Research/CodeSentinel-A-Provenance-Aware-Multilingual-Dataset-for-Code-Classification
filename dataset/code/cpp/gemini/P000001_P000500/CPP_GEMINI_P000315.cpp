#include <iostream>
#include <string>

int main() {
    std::string s;
    if (std::cin >> s) {
        long long res = 0;
        for (char c : s) {
            res = res * 26 + (c - 'A' + 1);
        }
        std::cout << res << std::endl;
    }
    return 0;
}