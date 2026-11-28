#include <iostream>
#include <string>
#include <vector>

void backtrack(const std::string& s, int index, std::vector<std::string>& parts, std::vector<std::string>& res) {
    if (parts.size() == 4) {
        if (index == (int)s.length()) {
            res.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
        }
        return;
    }
    for (int len = 1; len <= 3 && index + len <= (int)s.length(); len++) {
        std::string segment = s.substr(index, len);
        if (segment.length() > 1 && segment[0] == '0') continue;
        int val = std::stoi(segment);
        if (val > 255) continue;
        parts.push_back(segment);
        backtrack(s, index + len, parts, res);
        parts.pop_back();
    }
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> parts;
        std::vector<std::string> res;
        backtrack(s, 0, parts, res);
        for (const auto& ip : res) {
            std::cout << ip << "\n";
        }
    }
    return 0;
}