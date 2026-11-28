#include <vector>
#include <stack>
class Solution {
public:
    std::vector<int> nextSmallerElement(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                res[st.top()] = nums[i]; st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
