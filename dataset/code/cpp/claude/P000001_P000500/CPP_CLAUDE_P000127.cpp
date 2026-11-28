#include <vector>
#include <algorithm>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1, best = 0;
        while (l < r) {
            best = std::max(best, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return best;
    }
};
