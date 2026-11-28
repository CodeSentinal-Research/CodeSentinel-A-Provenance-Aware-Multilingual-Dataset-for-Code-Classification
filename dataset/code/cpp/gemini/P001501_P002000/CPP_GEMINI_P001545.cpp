#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::deque<int> maxDq, minDq;
        int minDiff = INT_MAX;

        for (int i = 0; i < n; i++) {
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[i]) maxDq.pop_back();
            while (!minDq.empty() && nums[minDq.back()] >= nums[i]) minDq.pop_back();
            maxDq.push_back(i);
            minDq.push_back(i);

            while (maxDq.front() <= i - k) maxDq.pop_front();
            while (minDq.front() <= i - k) minDq.pop_front();

            if (i >= k - 1) {
                minDiff = std::min(minDiff, nums[maxDq.front()] - nums[minDq.front()]);
            }
        }
        std::cout << minDiff << "\n";
    }
    return 0;
}