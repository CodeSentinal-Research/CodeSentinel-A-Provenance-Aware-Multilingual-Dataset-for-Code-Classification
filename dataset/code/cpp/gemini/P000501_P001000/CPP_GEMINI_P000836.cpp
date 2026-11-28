#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int left = 1, right = position.back() - position.front();
        int ans = 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int count = 1, last = position[0];
            for (size_t i = 1; i < position.size(); i++) {
                if (position[i] - last >= mid) {
                    count++;
                    last = position[i];
                }
            }
            if (count >= m) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};