#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

std::unordered_map<std::string, std::vector<std::string>> memo;

std::vector<std::string> dfs(const std::string& s, const std::unordered_set<std::string>& dict) {
    if (memo.count(s)) return memo[s];
    if (s.empty()) return {""};
    std::vector<std::string> res;
    for (const auto& word : dict) {
        if (s.rfind(word, 0) == 0) {
            std::vector<std::string> sub = dfs(s.substr(word.length()), dict);
            for (const auto& str : sub) {
                res.push_back(word + (str.empty() ? "" : " " + str));
            }
        }
    }
    return memo[s] = res;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<std::string> dict;
        std::string word;
        while (std::cin >> word) {
            dict.insert(word);
        }
        std::vector<std::string> res = dfs(s, dict);
        for (const auto& sentence : res) {
            std::cout << sentence << "\n";
        }
    }
    return 0;
}