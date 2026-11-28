#include <iostream>
#include <string>
#include <cmath>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::string st = "";
        for (char c : s) {
            if (!st.empty() && std::abs(st.back() - c) == 32) st.pop_back();
            else st.push_back(c);
        }
        std::cout << st << std::endl;
    }
    return 0;
}