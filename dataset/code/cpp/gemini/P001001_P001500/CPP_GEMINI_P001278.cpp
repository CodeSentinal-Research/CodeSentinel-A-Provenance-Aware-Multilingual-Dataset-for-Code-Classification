#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    int maxChunksToSorted(std::vector<int>& arr) {
        std::vector<int> stack;
        for (int x : arr) {
            int curMax = x;
            while (!stack.empty() && stack.back() > x) {
                curMax = std::max(curMax, stack.back());
                stack.pop_back();
            }
            stack.push_back(curMax);
        }
        return stack.size();
    }
};