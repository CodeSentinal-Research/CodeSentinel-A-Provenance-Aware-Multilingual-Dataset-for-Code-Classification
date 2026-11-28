#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::deque<int> dq;
        for (size_t i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] >= nums[i]) dq.pop_back();
            dq.push_back(i);

            while (dq.front() <= (int)i - k) dq.pop_front();

            if ((int)i >= k - 1) {
                std::cout << nums[dq.front()] << (i == nums.size() - 1 ? "" : " ");
            }
        }
        std::cout << "\n";
    }
    return 0;
}