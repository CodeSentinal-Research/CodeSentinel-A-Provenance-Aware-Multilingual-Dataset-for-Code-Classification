#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::vector<std::string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        std::unordered_set<std::string> set;

        for (const auto& w : words) {
            std::string code = "";
            for (char c : w) code += morse[c - 'a'];
            set.insert(code);
        }
        return set.size();
    }
};