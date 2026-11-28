#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextSmallerElement(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        std::stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Maintain monotonic stack property by popping smaller elements
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(nums[i]);
        }
        return res;
    }
};

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        Solution sol;
        std::vector<int> result = sol.nextSmallerElement(nums);

        for (int i = 0; i < n; ++i) {
            std::cout << result[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
