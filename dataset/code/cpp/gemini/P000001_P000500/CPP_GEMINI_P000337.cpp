#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    if (std::cin >> s) {
        int ones = 0;
        for (char c : s) if (c == '1') ones++;
        int max_score = 0, zeros = 0;
        for (size_t i = 0; i + 1 < s.length(); i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            max_score = std::max(max_score, zeros + ones);
        }
        std::cout << max_score << std::endl;
    }
    return 0;
}