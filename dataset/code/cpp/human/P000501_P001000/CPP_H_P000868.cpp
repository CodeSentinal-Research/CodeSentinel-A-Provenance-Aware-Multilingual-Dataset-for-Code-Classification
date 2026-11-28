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
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 8 * sizeof(int); ++i) {
            vector<int> counts(2);
            for (const auto& num : nums) {
                ++counts[(num >> i) & 1];
            }
            result += counts[0] * counts[1];
        }
        return result;
    }
};
