#include <string>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, int> getFrequencies(std::string s) {
        std::unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        return freq;
    }
};