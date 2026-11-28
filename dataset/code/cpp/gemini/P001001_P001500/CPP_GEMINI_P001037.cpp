#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        int count[26] = {0};
        int maxFreq = 0;
        for (char c : tasks) {
            count[c - 'A']++;
            maxFreq = std::max(maxFreq, count[c - 'A']);
        }
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == maxFreq) maxCount++;
        }
        return std::max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
    }
};