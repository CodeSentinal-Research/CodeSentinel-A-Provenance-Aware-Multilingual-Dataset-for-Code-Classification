#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::vector<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.back()] > nums[i]) st.push_back(i);
        }
        int max_w = 0;
        for (int j = n - 1; j >= 0; j--) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && nums[st.back()] <= nums[j]) {
                max_w = std::max(max_w, j - st.back());
                st.pop_back();
            }
        }
        std::cout << max_w << std::endl;
    }
    return 0;
}