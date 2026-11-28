#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::string s; long long k;
    if (std::cin >> s >> k) {
        long long size = 0;
        for (char c : s) {
            if (std::isdigit(c)) size *= (c - '0');
            else size++;
        }
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            char c = s[i];
            k %= size;
            if (k == 0 && std::isalpha(c)) {
                std::cout << c << std::endl;
                return 0;
            }
            if (std::isdigit(c)) size /= (c - '0');
            else size--;
        }
    }
    return 0;
}