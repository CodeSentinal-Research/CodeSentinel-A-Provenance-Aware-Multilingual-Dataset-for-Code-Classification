#include <iostream>
#include <string>

int main() {
    std::string s;
    if (std::cin >> s) {
        std::string res = "";
        for (char c : s) {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}