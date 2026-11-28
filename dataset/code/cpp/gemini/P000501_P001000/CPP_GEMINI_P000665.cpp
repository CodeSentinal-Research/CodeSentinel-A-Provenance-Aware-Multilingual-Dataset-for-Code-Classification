#include <iostream>
#include <vector>
#include <string>
int main() {
    std::string s;
    std::vector<std::string> tokens;
    while (std::cin >> s) tokens.push_back(s);
    if (tokens.empty()) return 0;
    int start = 0;
    if (tokens.size() > 1 && std::stoi(tokens[0]) == (int)tokens.size() - 1) start = 1;
    for (int i = (int)tokens.size() - 1; i >= start; i--) {
        std::cout << tokens[i] << (i == start ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}