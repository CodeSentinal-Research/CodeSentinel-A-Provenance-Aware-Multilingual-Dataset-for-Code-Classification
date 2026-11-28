#include <string>
#include <vector>

class Solution {
public:
    bool validAnagramAfterRemoval(std::string s, std::string t) {
        if (s.size() != t.size() + 1) return false;
        std::vector<int> freqS(256, 0), freqT(256, 0);

        for (char c : s) freqS[(unsigned char)c]++;
        for (char c : t) freqT[(unsigned char)c]++;

        int diff = 0;
        for (int i = 0; i < 256; i++) {
            if (freqS[i] > freqT[i]) diff += freqS[i] - freqT[i];
            else if (freqS[i] < freqT[i]) return false;
        }
        return diff == 1;
    }
};