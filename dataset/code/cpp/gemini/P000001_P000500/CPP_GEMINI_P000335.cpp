#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> tokens;
    std::string s;
    while (std::cin >> s) tokens.push_back(s);
    if (!tokens.empty()) {
        std::string pattern = tokens.back();
        for (size_t k = 0; k + 1 < tokens.size(); k++) {
            std::string q = tokens[k];
            size_t i = 0;
            bool ok = true;
            for (char c : q) {
                if (i < pattern.length() && c == pattern[i]) {
                    i++;
                } else if (isupper(c)) {
                    ok = false;
                    break;
                }
            }
            std::cout << (ok && i == pattern.length() ? "true" : "false") << "\n";
        }
    }
    return 0;
}