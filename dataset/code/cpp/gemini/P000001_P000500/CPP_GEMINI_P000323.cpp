#include <iostream>
#include <string>

bool checkRecord(std::string s) {
    int a_cnt = 0;
    for (char c : s) {
        if (c == 'A') {
            a_cnt++;
            if (a_cnt >= 2) return false;
        }
    }
    return s.find("LLL") == std::string::npos;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (checkRecord(s) ? "Yes" : "No") << std::endl;
    }
    return 0;
}