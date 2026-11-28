#include <vector>
#include <algorithm>

class Solution {
public:
    int maxScore(std::vector<int>& nums) {
        std::sort(nums.rbegin(), nums.rend());
        long long prefix = 0;
        int score = 0;

        for (int x : nums) {
            prefix += x;
            if (prefix > 0) score++;
            else break;
        }
        return score;
    }
};