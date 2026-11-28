#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        long long even = 0, odd = 0;
        for (int x : nums) {
            even = std::max(even, odd + x);
            odd = std::max(odd, even - x);
        }
        return even;
    }
};