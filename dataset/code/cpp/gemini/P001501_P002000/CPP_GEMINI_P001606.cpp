#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::unordered_map<int, int> count;
        count[0] = 1;
        int curSum = 0;
        long long ans = 0;

        for (int x : nums) {
            curSum += (x == 1 ? 1 : -1);
            ans += count[curSum];
            count[curSum]++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}