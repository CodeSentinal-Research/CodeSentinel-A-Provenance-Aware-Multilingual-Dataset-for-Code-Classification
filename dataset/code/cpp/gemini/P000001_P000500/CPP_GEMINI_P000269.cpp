#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        while (ss >> word) words.push_back(word);

        std::string res = "";
        for (int i = (int)words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};