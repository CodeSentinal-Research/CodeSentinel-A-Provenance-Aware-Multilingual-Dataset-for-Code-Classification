#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDiff(std::vector<int>& arr) {
        if (arr.size() < 2) return 0;
        int minVal = arr[0];
        int maxDiff = arr[1] - arr[0];

        for (size_t i = 1; i < arr.size(); i++) {
            maxDiff = std::max(maxDiff, arr[i] - minVal);
            minVal = std::min(minVal, arr[i]);
        }
        return maxDiff;
    }
};