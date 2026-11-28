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
    int maximumDifference(vector<int>& nums) {
        int result = 0, prefix = numeric_limits<int>::max();
        for (const auto& x : nums) {
            result = max(result, x - prefix);
            prefix = min(prefix, x);
        }
        return result ? result : -1;
    }
};
