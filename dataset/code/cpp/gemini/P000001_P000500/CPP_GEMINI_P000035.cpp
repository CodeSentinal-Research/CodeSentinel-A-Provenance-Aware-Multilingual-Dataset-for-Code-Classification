#include <iostream>
#include <string>
#include <algorithm>
int main() {
    unsigned int n;
    if (std::cin >> n) {
        if (n == 0) { std::cout << "0" << std::endl; return 0; }
        std::string s = "";
        while (n > 0) {
            s += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        std::reverse(s.begin(), s.end());
        std::cout << s << std::endl;
    }
    return 0;
}