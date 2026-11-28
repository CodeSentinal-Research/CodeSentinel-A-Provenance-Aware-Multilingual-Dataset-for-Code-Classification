#include <vector>
#include <algorithm>

class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        std::vector<int> lengths(n, 1), counts(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (lengths[j] + 1 > lengths[i]) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } else if (lengths[j] + 1 == lengths[i]) {
                        counts[i] += counts[j];
                    }
                }
            }
        }

        int maxLen = *std::max_element(lengths.begin(), lengths.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (lengths[i] == maxLen) ans += counts[i];
        }
        return ans;
    }
};