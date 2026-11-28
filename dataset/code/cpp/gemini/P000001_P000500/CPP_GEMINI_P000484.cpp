#include <iostream>
#include <string>
#include <vector>
#include <cctype>
std::string decodeString(const std::string& s) {
    std::vector<std::pair<std::string, int>> st;
    std::string curr_str = "";
    int curr_num = 0;
    for (char c : s) {
        if (std::isdigit(c)) {
            curr_num = curr_num * 10 + (c - '0');
        } else if (c == '[') {
            st.push_back({curr_str, curr_num});
            curr_str = "";
            curr_num = 0;
        } else if (c == ']') {
            auto [prev_str, num] = st.back();
            st.pop_back();
            std::string temp = "";
            for (int i = 0; i < num; i++) temp += curr_str;
            curr_str = prev_str + temp;
        } else {
            curr_str += c;
        }
    }
    return curr_str;
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << decodeString(s) << std::endl;
    }
    return 0;
}