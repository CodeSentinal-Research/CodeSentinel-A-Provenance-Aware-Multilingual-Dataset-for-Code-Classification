#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isSubsequence(const std::string& sub, const std::string& s) {
    size_t i = 0;
    for (char c : s) {
        if (i < sub.length() && c == sub[i]) i++;
    }
    return i == sub.length();
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> words;
        std::string w;
        while (std::cin >> w) words.push_back(w);
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            if (a.length() != b.length()) return a.length() > b.length();
            return a < b;
        });
        std::string best = "";
        for (const auto& word : words) {
            if (isSubsequence(word, s)) {
                best = word;
                break;
            }
        }
        std::cout << best << std::endl;
    }
    return 0;
}