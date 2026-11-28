#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    int b1, b2;
    if (std::cin >> s >> b1 >> b2) {
        long long val = std::stoll(s, nullptr, b1);
        if (val == 0) {
            std::cout << "0\n";
            return 0;
        }
        std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string res = "";
        while (val > 0) {
            res += digits[val % b2];
            val /= b2;
        }
        std::reverse(res.begin(), res.end());
        std::cout << res << "\n";
    }
    return 0;
}