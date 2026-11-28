#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> leaders(std::vector<int>& arr) {
        std::vector<int> res;
        int maxFromRight = INT_MIN;
        for (int i = (int)arr.size() - 1; i >= 0; i--) {
            if (arr[i] >= maxFromRight) {
                res.push_back(arr[i]);
                maxFromRight = arr[i];
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};