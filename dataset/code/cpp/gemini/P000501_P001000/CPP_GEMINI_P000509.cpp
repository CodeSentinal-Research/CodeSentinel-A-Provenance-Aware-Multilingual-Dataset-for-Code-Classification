#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::string st = "";
        for (char c : s) {
            if (std::isdigit(c)) {
                // Can also see the next taller person
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        std::cout << st << std::endl;
    }
    return 0;
}