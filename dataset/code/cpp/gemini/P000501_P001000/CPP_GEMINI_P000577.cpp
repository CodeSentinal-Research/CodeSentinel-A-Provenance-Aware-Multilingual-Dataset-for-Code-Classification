#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
int main() {
    std::string token;
    std::vector<std::string> tokens;
    while (std::cin >> token) tokens.push_back(token);
    if (tokens.empty() || tokens[0] == "null" || tokens[0] == "#" || tokens[0] == "N") return 0;
    std::map<int, int> bottom;
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [idx, col] = q.front(); q.pop();
        if (idx >= (int)tokens.size() || tokens[idx] == "null" || tokens[idx] == "#" || tokens[idx] == "N") continue;
        bottom[col] = std::stoi(tokens[idx]);
        int l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < (int)tokens.size()) q.push({l, col - 1});
        if (r < (int)tokens.size()) q.push({r, col + 1});
    }
    bool first = true;
    for (const auto& [c, val] : bottom) {
        if (!first) std::cout << " ";
        std::cout << val;
        first = false;
    }
    std::cout << std::endl;
    return 0;
}