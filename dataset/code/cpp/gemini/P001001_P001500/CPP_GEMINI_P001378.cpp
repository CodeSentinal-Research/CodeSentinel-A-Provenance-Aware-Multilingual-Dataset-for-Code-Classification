#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string w;
        while (iss >> w) words.push_back(w);

        if (pattern.length() != words.size()) return false;

        std::unordered_map<char, std::string> pToW;
        std::unordered_map<std::string, char> wToP;

        for (size_t i = 0; i < pattern.length(); i++) {
            char p = pattern[i];
            std::string word = words[i];
            if (pToW.count(p) && pToW[p] != word) return false;
            if (wToP.count(word) && wToP[word] != p) return false;
            pToW[p] = word;
            wToP[word] = p;
        }
        return true;
    }
};