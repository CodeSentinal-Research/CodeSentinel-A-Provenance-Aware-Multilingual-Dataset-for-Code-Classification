#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

bool wordPattern(std::string pattern, std::string s) {
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> words;
    while (ss >> word) words.push_back(word);
    if (pattern.length() != words.size()) return false;
    std::unordered_map<char, std::string> pw;
    std::unordered_map<std::string, char> wp;
    for (size_t i = 0; i < pattern.length(); i++) {
        char p = pattern[i];
        std::string w = words[i];
        if (pw.count(p) && pw[p] != w) return false;
        if (wp.count(w) && wp[w] != p) return false;
        pw[p] = w;
        wp[w] = p;
    }
    return true;
}

int main() {
    std::string pattern, s;
    if (std::cin >> pattern) {
        std::cin.ignore();
        if (std::getline(std::cin, s)) {
            std::cout << (wordPattern(pattern, s) ? "Yes" : "No") << std::endl;
        }
    }
    return 0;
}