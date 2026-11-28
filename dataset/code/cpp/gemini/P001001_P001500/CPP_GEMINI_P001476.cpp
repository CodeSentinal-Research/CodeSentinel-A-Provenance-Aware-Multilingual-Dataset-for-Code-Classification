#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.empty()) return 0;
        int l = 0, r = (int)height.size() - 1;
        int lMax = height[l], rMax = height[r];
        int water = 0;

        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = std::max(lMax, height[l]);
                water += lMax - height[l];
            } else {
                r--;
                rMax = std::max(rMax, height[r]);
                water += rMax - height[r];
            }
        }
        return water;
    }
};