#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void backtrack(const std::string& word, int idx, std::string cur, int count, std::vector<std::string>& res) {
    if (idx == (int)word.length()) {
        res.push_back(cur + (count > 0 ? std::to_string(count) : ""));
        return;
    }
    backtrack(word, idx + 1, cur, count + 1, res);
    backtrack(word, idx + 1, cur + (count > 0 ? std::to_string(count) : "") + word[idx], 0, res);
}
int main() {
    std::string word;
    if (std::cin >> word) {
        std::vector<std::string> res;
        backtrack(word, 0, "", 0, res);
        std::sort(res.begin(), res.end());
        for (const auto& s : res) std::cout << s << std::endl;
    }
    return 0;
}