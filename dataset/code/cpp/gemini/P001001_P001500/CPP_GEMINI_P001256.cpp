#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int minDeletions(std::string s) {
        std::vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        std::unordered_set<int> used;
        int deletions = 0;

        for (int freq : count) {
            while (freq > 0 && used.count(freq)) {
                freq--;
                deletions++;
            }
            used.insert(freq);
        }
        return deletions;
    }
};