#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
int main() {
    std::string token;
    std::vector<std::string> tokens;
    while (std::cin >> token) tokens.push_back(token);
    if (tokens.empty() || tokens[0] == "null" || tokens[0] == "#" || tokens[0] == "N") {
        std::cout << 0 << std::endl; return 0;
    }
    std::queue<std::pair<int, unsigned long long>> q;
    q.push({0, 1});
    unsigned long long max_w = 0;
    while (!q.empty()) {
        int sz = q.size();
        unsigned long long first_pos = q.front().second, last_pos = q.back().second;
        max_w = std::max(max_w, last_pos - first_pos + 1);
        for (int i = 0; i < sz; i++) {
            auto [idx, pos] = q.front(); q.pop();
            int l = 2 * idx + 1, r = 2 * idx + 2;
            if (l < (int)tokens.size() && tokens[l] != "null" && tokens[l] != "#" && tokens[l] != "N") {
                q.push({l, 2 * pos});
            }
            if (r < (int)tokens.size() && tokens[r] != "null" && tokens[r] != "#" && tokens[r] != "N") {
                q.push({r, 2 * pos + 1});
            }
        }
    }
    std::cout << max_w << std::endl;
    return 0;
}