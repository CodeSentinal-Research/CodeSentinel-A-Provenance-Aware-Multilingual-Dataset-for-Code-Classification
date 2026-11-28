#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minDiff(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (size_t i = 1; i < arr.size(); i++) {
            minDiff = std::min(minDiff, arr[i] - arr[i - 1]);
        }
        return minDiff;
    }
};