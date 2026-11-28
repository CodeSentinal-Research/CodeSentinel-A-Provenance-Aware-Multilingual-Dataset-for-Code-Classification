#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdint>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
using namespace std;

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const auto total = accumulate(nums.begin(), nums.end(), 0);
        auto left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum == (total - left_sum - nums[i])) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};
