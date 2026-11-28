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
    int count = (int)tokens.size() - start;
    // Calculate midpoint to prevent potential overflow
    int mid = (count + 1) / 2;
    for (int i = 0; i < mid; i++) {
        std::cout << tokens[start + i] << (i == mid - 1 ? "" : " ");
    }
    std::cout << std::endl;
    for (int i = mid; i < count; i++) {
        std::cout << tokens[start + i] << (i == count - 1 ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}