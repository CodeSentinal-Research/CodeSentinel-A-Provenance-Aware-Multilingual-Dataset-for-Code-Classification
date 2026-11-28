#include <vector>

class Solution {
public:
    std::vector<int> separateEvenOdd(std::vector<int>& nums) {
        std::vector<int> evens, odds;
        for (int x : nums) {
            if (x % 2 == 0) evens.push_back(x);
            else odds.push_back(x);
        }
        evens.insert(evens.end(), odds.begin(), odds.end());
        return evens;
    }
};

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    Solution sol;
    std::vector<int> result = sol.separateEvenOdd(nums);

    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}
