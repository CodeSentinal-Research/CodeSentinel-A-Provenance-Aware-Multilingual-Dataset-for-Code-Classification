#include <iostream>
#include <string>
#include <algorithm>

int main() {
    unsigned long long n;
    if (std::cin >> n) {
        if (n == 0) {
            std::cout << "0\n";
            return 0;
        }
        std::string s = "";
        while (n > 0) {
            s += (n % 2 == 1 ? '1' : '0');
            n /= 2;
        }
        std::reverse(s.begin(), s.end());
        std::cout << s << "\n";
    }
    return 0;
}