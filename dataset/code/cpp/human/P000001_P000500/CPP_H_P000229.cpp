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

// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> result = {-1, -1};
        for (int i = 0; i < size(mat); ++i) {
            const int curr = accumulate(cbegin(mat[i]), cend(mat[i]), 0);
            if (curr > result[1]) {
                result = {i, curr};
            }
        }
        return result;
    }
};
