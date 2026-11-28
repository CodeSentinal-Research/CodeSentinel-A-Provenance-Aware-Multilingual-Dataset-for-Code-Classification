#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    int k;
    if (std::cin >> s >> k) {
        for (int i = 0; i < (int)s.length(); i += 2 * k) {
            int end = std::min(i + k, (int)s.length());
            std::reverse(s.begin() + i, s.begin() + end);
        }
        std::cout << s << std::endl;
    }
    return 0;
}