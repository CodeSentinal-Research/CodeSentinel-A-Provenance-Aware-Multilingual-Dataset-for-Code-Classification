#include <vector>

class Solution {
public:
    std::vector<int> rearrange(std::vector<int>& nums) {
        std::vector<int> pos, neg;
        for (int x : nums) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }
        pos.insert(pos.end(), neg.begin(), neg.end());
        return pos;
    }
};