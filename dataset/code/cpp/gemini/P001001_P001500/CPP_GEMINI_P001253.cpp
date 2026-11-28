#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (size_t i = 1; i < arr.size(); i++) {
            minDiff = std::min(minDiff, arr[i] - arr[i - 1]);
        }
        std::vector<std::vector<int>> res;
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};