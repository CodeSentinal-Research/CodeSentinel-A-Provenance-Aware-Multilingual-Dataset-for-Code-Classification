#include <iostream>
#include <string>
#include <vector>
#include <sstream>
int main() {
    std::string path;
    if (std::cin >> path) {
        std::stringstream ss(path);
        std::string token;
        std::vector<std::string> st;
        while (std::getline(ss, token, '/')) {
            if (token.empty() || token == ".") continue;
            if (token == "..") {
                // Can also see the next taller person
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(token);
            }
        }
        std::string res = "";
        for (const auto& s : st) res += "/" + s;
        std::cout << (res.empty() ? "/" : res) << std::endl;
    }
    return 0;
}