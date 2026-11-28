#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> tokens;
    std::string token;
    while (std::cin >> token) tokens.push_back(token);
    if (!tokens.empty()) {
        std::string s = tokens.back();
        int count = 0;
        for (size_t i = 0; i + 1 < tokens.size(); i++) {
            if (s.rfind(tokens[i], 0) == 0) count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}