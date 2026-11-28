#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    bool areElementsContiguous(std::vector<int>& arr) {
        std::unordered_set<int> s(arr.begin(), arr.end());
        int minV = *std::min_element(arr.begin(), arr.end());
        int maxV = *std::max_element(arr.begin(), arr.end());
        return (maxV - minV + 1) == (int)s.size();
    }
};