#include <iostream>
#include <vector>
#include <deque>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k;
        std::cin >> k;
        std::deque<int> q;
        std::vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() < i - k + 1) q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        for (size_t i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}