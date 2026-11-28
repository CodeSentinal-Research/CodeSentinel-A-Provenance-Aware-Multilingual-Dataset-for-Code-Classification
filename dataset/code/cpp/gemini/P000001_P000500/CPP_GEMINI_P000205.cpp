#include <vector>
#include <algorithm>

class Solution {
public:
    double getMedian(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::vector<int> merged = arr1;
        merged.insert(merged.end(), arr2.begin(), arr2.end());
        std::sort(merged.begin(), merged.end());
        int n = arr1.size();
        return (merged[n - 1] + merged[n]) / 2.0;
    }
};