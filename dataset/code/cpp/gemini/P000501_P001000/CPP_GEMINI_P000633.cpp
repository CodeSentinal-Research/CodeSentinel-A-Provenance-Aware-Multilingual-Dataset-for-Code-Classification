#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string s;
    std::vector<std::string> tokens;
    while (std::cin >> s) tokens.push_back(s);
    if (tokens.empty()) return 0;
    int start = 0;
    if (tokens.size() > 1 && std::stoi(tokens[0]) == (int)tokens.size() - 1) start = 1;
    for (size_t i = start; i < tokens.size(); i++) {
        std::cout << tokens[i] << (i + 1 == tokens.size() ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}