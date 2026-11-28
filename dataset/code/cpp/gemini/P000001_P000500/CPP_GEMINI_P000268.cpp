#include <string>
#include <sstream>

class Solution {
public:
    int countWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        int count = 0;
        while (ss >> word) count++;
        return count;
    }
};