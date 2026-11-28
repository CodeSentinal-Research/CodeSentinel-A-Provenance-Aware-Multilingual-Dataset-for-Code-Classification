#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k; std::cin >> k;
        std::unordered_map<long long, int> counts;
        counts[0] = 1;
        long long cur = 0, ans = 0;
        for (int x : nums) {
            cur += x;
            if (counts.count(cur - k)) ans += counts[cur - k];
            counts[cur]++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}