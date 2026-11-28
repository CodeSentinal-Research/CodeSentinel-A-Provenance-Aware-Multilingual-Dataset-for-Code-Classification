#include <iostream>
#include <vector>
#include <string>
#include <queue>
int main() {
    std::string token;
    std::vector<std::string> tokens;
    while (std::cin >> token) tokens.push_back(token);
    if (tokens.empty() || tokens[0] == "null" || tokens[0] == "#" || tokens[0] == "N") return 0;
    std::vector<std::vector<int>> levels;
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [idx, lvl] = q.front(); q.pop();
        if (idx >= (int)tokens.size() || tokens[idx] == "null" || tokens[idx] == "#" || tokens[idx] == "N") continue;
        if (lvl >= (int)levels.size()) levels.push_back({});
        levels[lvl].push_back(std::stoi(tokens[idx]));
        int l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < (int)tokens.size()) q.push({l, lvl + 1});
        if (r < (int)tokens.size()) q.push({r, lvl + 1});
    }
    for (const auto& lvl : levels) {
        for (size_t i = 0; i < lvl.size(); i++) {
            std::cout << lvl[i] << (i + 1 == lvl.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}