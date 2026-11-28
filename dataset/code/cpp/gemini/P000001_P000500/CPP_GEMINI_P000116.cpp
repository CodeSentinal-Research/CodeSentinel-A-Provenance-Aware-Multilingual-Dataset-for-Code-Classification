#include <vector>
#include <numeric>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n + 1) / 2;
        int actual = std::accumulate(nums.begin(), nums.end(), 0);
        return expected - actual;
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
        Solution solution;
        std::cout << solution.missingNumber(nums) << "\n";
    }

    return 0;
}
