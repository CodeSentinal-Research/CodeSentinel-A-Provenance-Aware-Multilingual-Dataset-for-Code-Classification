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

// dp
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int64_t result = 0;
        for (int i = 0, curr = 0; i < size(nums); ++i) {
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                curr = 0;
            }
            result += ++curr;
        }
        return result;
    }
};
