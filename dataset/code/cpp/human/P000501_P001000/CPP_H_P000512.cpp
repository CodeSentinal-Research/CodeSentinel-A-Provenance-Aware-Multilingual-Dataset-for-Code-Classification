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
// Space: O(n)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        vector<int> s;
        for (const auto& v : pushed) {
            s.emplace_back(v);
            while (!s.empty() &&
                   i < popped.size() &&
                   s.back() == popped[i]) {
                s.pop_back();
                ++i;
            }
        }
        return i == popped.size();
    }
};
