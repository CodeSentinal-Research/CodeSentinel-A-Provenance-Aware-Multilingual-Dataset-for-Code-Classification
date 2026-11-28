#include <vector>
#include <utility>
class Solution {
public:
    std::pair<int,int> countEvenOdd(std::vector<int>& nums) {
        int even = 0;
        for (int x : nums) if (x % 2 == 0) even++;
        return {even, (int)nums.size() - even};
    }
};
