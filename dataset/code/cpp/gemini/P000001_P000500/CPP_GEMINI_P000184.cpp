#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lenOfLongSubarr(std::vector<int>& arr, int k) {
        std::unordered_map<long long, int> map;
        long long curSum = 0;
        int maxLen = 0;

        for (int i = 0; i < (int)arr.size(); i++) {
            curSum += arr[i];
            if (curSum == k) {
                maxLen = i + 1;
            } else if (map.count(curSum - k)) {
                maxLen = std::max(maxLen, i - map[curSum - k]);
            }
            if (!map.count(curSum)) {
                map[curSum] = i;
            }
        }
        return maxLen;
    }
};