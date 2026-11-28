#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;
        while (l < r) {
            int h = std::min(height[l], height[r]);
            maxWater = std::max(maxWater, h * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};