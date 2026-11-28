#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int findMaximumXOR(std::vector<int>& nums) {
        int maxXor = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            std::unordered_set<int> prefixes;
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            int greedyTarget = maxXor | (1 << i);
            for (int p : prefixes) {
                if (prefixes.find(p ^ greedyTarget) != prefixes.end()) {
                    maxXor = greedyTarget;
                    break;
                }
            }
        }
        return maxXor;
    }
};