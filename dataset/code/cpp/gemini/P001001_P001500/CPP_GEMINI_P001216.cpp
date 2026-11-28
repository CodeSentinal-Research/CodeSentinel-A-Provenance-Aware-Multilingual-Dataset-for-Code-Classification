#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

class Solution {
public:
    int mctFromLeafValues(std::vector<int>& arr) {
        int res = 0;
        std::vector<int> stack = {INT_MAX};
        for (int x : arr) {
            while (stack.back() <= x) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * std::min(stack.back(), x);
            }
            stack.push_back(x);
        }
        while (stack.size() > 2) {
            int mid = stack.back();
            stack.pop_back();
            res += mid * stack.back();
        }
        return res;
    }
};