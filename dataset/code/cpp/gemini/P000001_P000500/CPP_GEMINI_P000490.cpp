#include <iostream>
#include <string>
std::string process(const std::string& s) {
    std::string res = "";
    for (char c : s) {
        if (c == '#') {
            if (!res.empty()) res.pop_back();
        } else {
            res.push_back(c);
        }
    }
    return res;
}
int main() {
    std::string s, t = "";
    if (std::cin >> s) {
        std::cin >> t;
        std::cout << (process(s) == process(t) ? "true" : "false") << std::endl;
    }
    return 0;
}